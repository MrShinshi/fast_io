#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_driver/timer.h>
#include <vector>
#include <string>
#include <fast_io_dsal/string.h>
#include <charconv>
#include <fast_float/fast_float.h>
#include <limits>

using namespace fast_io::io;

// NOTE:
// This benchmark compares the core integer parsing routines under identical preconditions.
// For each line, the pointer `p` is positioned at the first decimal digit; there is no
// leading whitespace, sign character, or base prefix in the [p, end) slice.
// The fast_io branch calls
//   scan_int_contiguous_none_simd_space_part_define_impl<10, char>(p, end, v);
// the std::from_chars and fast_float::from_chars integer overloads are invoked on the same
// [p, end) range.
// By specification, std::from_chars and fast_float::from_chars for integer types do not
// skip leading whitespace, and scan_int_contiguous_none_simd_space_part_define_impl makes
// the same assumption that any preceding whitespace has already been consumed. Thus the
// starting conditions and termination rules are fully aligned, providing a fair comparison
// of "decimal digit substring → uint64_t" parsing performance.

static std::string make_numbers_buffer(std::size_t n)
{
	std::string s;
	s.reserve(n * 8);
	for (std::size_t i{}; i != n; ++i)
	{
		auto old = s.size();
		s.resize(old + 32);
		auto *first = s.data() + old;
		auto *last = s.data() + s.size();
		auto res = std::to_chars(first, last - 1, i);
		*res.ptr = '\n';
		s.resize(res.ptr - s.data() + 1);
	}
	return s;
}

static std::string make_fixed_digits_numbers_buffer(std::size_t digits, std::size_t n)
{
	constexpr std::uint64_t pow10[20]{
		1ull,
		10ull,
		100ull,
		1000ull,
		10000ull,
		100000ull,
		1000000ull,
		10000000ull,
		100000000ull,
		1000000000ull,
		10000000000ull,
		100000000000ull,
		1000000000000ull,
		10000000000000ull,
		100000000000000ull,
		1000000000000000ull,
		10000000000000000ull,
		100000000000000000ull,
		1000000000000000000ull,
		10000000000000000000ull};

	if (digits == 0 || digits > 20)
	{
		return {};
	}

	std::string s;
	s.reserve(n * (digits + 1));

	std::uint64_t lo{};
	std::uint64_t count{};

	if (digits == 1)
	{
		lo = 0;
		count = 10;
	}
	else if (digits < 20)
	{
		lo = pow10[digits - 1];
		count = pow10[digits] - lo;
	}
	else
	{
		lo = pow10[19];
		count = (std::numeric_limits<std::uint64_t>::max)() - lo + 1;
	}

	for (std::size_t i{}; i != n; ++i)
	{
		auto old = s.size();
		s.resize(old + 32);
		auto *first = s.data() + old;
		auto *last = s.data() + s.size();
		std::uint64_t value = lo + static_cast<std::uint64_t>(i % count);
		auto res = std::to_chars(first, last - 1, value);
		*res.ptr = '\n';
		s.resize(static_cast<std::size_t>(res.ptr - s.data() + 1));
	}
	return s;
}

int main()
{
	constexpr std::size_t N = 10'000'000;
	auto buf = make_numbers_buffer(N);
	char const *begin = buf.data();
	char const *end = buf.data() + buf.size();

	{
		std::size_t lines{};
		for (char const *p = begin; p < end; ++p)
		{
			lines += (*p == '\n');
		}
		fast_io::perrln("lines=", lines);
	}

	// atoi
	{
		fast_io::timer t(u8"atoi");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			int v = std::atoi(p);
			sum += static_cast<std::uint64_t>(v);
			while (p < end && *p >= '0' && *p <= '9')
			{
				++p;
			}
			if (p < end && *p == '\n')
			{
				++p;
			}
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}

	// std::from_chars
	{
		fast_io::timer t(u8"std_from_chars");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = std::from_chars(p, end, v);
			sum += v;
			p = res.ptr;
			if (p < end && *p == '\n')
			{
				++p;
			}
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}


	// fast_io core sto (dec) - scalar/SWAR path:
	// scan_int_contiguous_none_simd_space_part_define_impl (no SSE4.1 fast path)
	{
		fast_io::timer t(u8"fastio_scan_int_none_simd_dec");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = ::fast_io::details::scan_int_contiguous_none_simd_space_part_define_impl<10, char>(
				p, end, v);
			if (res.code != fast_io::parse_code::ok)
			{
				break;
			}
			sum += v;
			p = res.iter;
			if (p < end && *p == '\n')
			{
				++p;
			}
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}

#if defined(__SSE4_1__) && (defined(__x86_64__) || defined(_M_AMD64))
	// fast_io core sto (dec) - SSE4.1-accelerated path:
	// scan_int_contiguous_none_space_part_define_impl (may use sse_parse for base-10)
	{
		fast_io::timer t(u8"fastio_scan_int_sse4_dec");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = ::fast_io::details::scan_int_contiguous_none_space_part_define_impl<10>(p, end, v);
			if (res.code != fast_io::parse_code::ok)
			{
				break;
			}
			sum += v;
			p = res.iter;
			if (p < end && *p == '\n')
			{
				++p;
			}
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}
#endif

	// fast_io char_digit_to_literal (hex)
	{
		fast_io::timer t(u8"fastio_char_digit_to_literal");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			using UCh = std::make_unsigned_t<char>;
			std::uint64_t v{};
			char const *q = p;
			while (q < end && *q != '\n')
			{
				UCh ch = static_cast<UCh>(*q);
				if (fast_io::details::char_digit_to_literal<10, char>(ch))
				{
					break;
				}
				v = v * 10 + static_cast<std::uint64_t>(ch);
				++q;
			}
			sum += v;
			p = (q < end ? q + 1 : q);
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}


	// fast_float
	{
		fast_io::timer t(u8"fast_float_from_chars");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = fast_float::from_chars(p, end, v);
			sum += v;
			p = res.ptr;
			if (p < end && *p == '\n')
			{
				++p;
			}
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}

	// Per-digit decimal benchmarks: 1-digit up to theoretical max decimal digits of uint64_t (20)
	{
		constexpr std::size_t max_digits = 20;
		for (std::size_t digits = 1; digits <= max_digits; ++digits)
		{
			auto buf_fixed = make_fixed_digits_numbers_buffer(digits, N);
			char const *fixed_begin = buf_fixed.data();
			char const *fixed_end = buf_fixed.data() + buf_fixed.size();

			fast_io::perrln("\n\nfixed_digits=", digits, " lines=", N);

			{
				std::size_t lines{};
				for (char const *p = fixed_begin; p < fixed_end; ++p)
				{
					lines += (*p == '\n');
				}
				fast_io::perrln("lines=", lines);
			}

			// atoi on fixed-width decimal substrings
			{
				fast_io::timer t(u8"atoi_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					int v = std::atoi(p);
					sum += static_cast<std::uint64_t>(v);
					while (p < fixed_end && *p >= '0' && *p <= '9')
					{
						++p;
					}
					if (p < fixed_end && *p == '\n')
					{
						++p;
					}
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}

			// std::from_chars on fixed-width decimal substrings
			{
				fast_io::timer t(u8"std_from_chars_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = std::from_chars(p, fixed_end, v);
					sum += v;
					p = res.ptr;
					if (p < fixed_end && *p == '\n')
					{
						++p;
					}
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}

			// fast_io char_digit_to_literal on fixed-width decimal substrings
			{
				fast_io::timer t(u8"fastio_char_digit_to_literal_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					using UCh = std::make_unsigned_t<char>;
					std::uint64_t v{};
					char const *q = p;
					while (q < fixed_end && *q != '\n')
					{
						UCh ch = static_cast<UCh>(*q);
						if (fast_io::details::char_digit_to_literal<10, char>(ch))
						{
							break;
						}
						v = v * 10 + static_cast<std::uint64_t>(ch);
						++q;
					}
					sum += v;
					p = (q < fixed_end ? q + 1 : q);
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}

			// fast_io core sto (dec) - scalar/SWAR path on fixed-width decimal substrings
			{
				fast_io::timer t(u8"fastio_scan_int_none_simd_dec_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = ::fast_io::details::scan_int_contiguous_none_simd_space_part_define_impl<10, char>(
						p, fixed_end, v);
					if (res.code != fast_io::parse_code::ok)
					{
						break;
					}
					sum += v;
					p = res.iter;
					if (p < fixed_end && *p == '\n')
					{
						++p;
					}
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}

#if defined(__SSE4_1__) && (defined(__x86_64__) || defined(_M_AMD64))
			// fast_io core sto (dec) - SSE4.1-accelerated path on fixed-width decimal substrings
			{
				fast_io::timer t(u8"fastio_scan_int_sse4_dec_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = ::fast_io::details::scan_int_contiguous_none_space_part_define_impl<10>(p, fixed_end, v);
					if (res.code != fast_io::parse_code::ok)
					{
						break;
					}
					sum += v;
					p = res.iter;
					if (p < fixed_end && *p == '\n')
					{
						++p;
					}
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}
#endif

			// fast_float integer from_chars on fixed-width decimal substrings
			{
				fast_io::timer t(u8"fast_float_from_chars_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = fast_float::from_chars(p, fixed_end, v);
					sum += v;
					p = res.ptr;
					if (p < fixed_end && *p == '\n')
					{
						++p;
					}
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}
		}
	}
}
