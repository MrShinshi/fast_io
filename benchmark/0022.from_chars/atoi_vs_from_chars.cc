#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_driver/timer.h>
#include <vector>
#include <string>
#include <fast_io_dsal/string.h>
#include <charconv>
#include <fast_float/fast_float.h>

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
		fast_io::println("lines=", lines);
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
}
