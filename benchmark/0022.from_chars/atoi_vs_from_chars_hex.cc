#include <fast_io.h>
#include <fast_io_device.h>
#include <fast_io_driver/timer.h>
#include <vector>
#include <string>
#include <fast_io_dsal/string.h>
#include <charconv>
#include <cstdlib>
#include <fast_float/fast_float.h>
#include <limits>

using namespace fast_io::io;

// NOTE:
// This benchmark compares core integer parsing in base 16 under aligned conditions.
// For each line, the pointer `p` is positioned at the first hexadecimal digit; there is no
// leading whitespace or base prefix in the [p, end) slice, and the 0–9/A–F/a–f pattern of
// each line is identical for all libraries. Newline characters '\n' are skipped manually.
// The fast_io branch calls
//   scan_int_contiguous_none_simd_space_part_define_impl<16, char>(p, end, v);
// the std::from_chars and fast_float::from_chars integer overloads are invoked on the same
// [p, end) range.
// As with the decimal benchmark, std::from_chars and fast_float::from_chars for integers
// do not skip leading whitespace, and scan_int_contiguous_none_simd_space_part_define_impl
// assumes that any preceding whitespace has already been consumed. The preconditions are
// therefore identical, making this a fair comparison of "hex digit substring → uint64_t"
// parsing performance.

static std::string make_hex_numbers_buffer(std::size_t n)
{
	std::string s;
	s.reserve(n * 8);
	for (std::size_t i{}; i != n; ++i)
	{
		auto old = s.size();
		s.resize(old + 32);
		auto *first = s.data() + old;
		auto *last = s.data() + s.size();
		auto res = std::to_chars(first, last - 1, i, 16);
		// mix lowercase/uppercase hex digits in the buffer
		if ((i & 1u) != 0u)
		{
			for (auto p = first; p != res.ptr; ++p)
			{
				if (*p >= 'a' && *p <= 'f')
				{
					*p = static_cast<char>(*p - 'a' + 'A');
				}
			}
		}
		*res.ptr = '\n';
		s.resize(static_cast<std::size_t>(res.ptr - s.data() + 1));
	}
	return s;
}

static std::string make_fixed_hex_numbers_buffer(std::size_t digits, std::size_t n)
{
	if (digits == 0 || digits > 16)
	{
		return {};
	}

	constexpr std::uint64_t pow16[16]{
		1ull,
		16ull,
		256ull,
		4096ull,
		65536ull,
		1048576ull,
		16777216ull,
		268435456ull,
		4294967296ull,
		68719476736ull,
		1099511627776ull,
		17592186044416ull,
		281474976710656ull,
		4503599627370496ull,
		72057594037927936ull,
		1152921504606846976ull};

	std::string s;
	s.reserve(n * (digits + 1));

	std::uint64_t lo{};
	std::uint64_t hi{};

	if (digits == 1)
	{
		lo = 0;
		hi = 0xFu;
	}
	else if (digits < 16)
	{
		lo = pow16[digits - 1];
		hi = pow16[digits] - 1;
	}
	else
	{
		lo = pow16[15];
		hi = (std::numeric_limits<std::uint64_t>::max)();
	}

	std::uint64_t count = hi - lo + 1;

	for (std::size_t i{}; i != n; ++i)
	{
		auto old = s.size();
		s.resize(old + 32);
		auto *first = s.data() + old;
		auto *last = s.data() + s.size();
		std::uint64_t value = lo + static_cast<std::uint64_t>(i % count);
		auto res = std::to_chars(first, last - 1, value, 16);
		// mix lowercase/uppercase hex digits in the buffer
		if ((value & 1u) != 0u)
		{
			for (auto p = first; p != res.ptr; ++p)
			{
				if (*p >= 'a' && *p <= 'f')
				{
					*p = static_cast<char>(*p - 'a' + 'A');
				}
			}
		}
		*res.ptr = '\n';
		s.resize(static_cast<std::size_t>(res.ptr - s.data() + 1));
	}
	return s;
}

int main()
{
	constexpr std::size_t N = 10'000'000;
	auto buf = make_hex_numbers_buffer(N);
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

	// strtoul (hex)
	{
		fast_io::timer t(u8"strtoul_hex");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			char *endptr{};
			auto v = std::strtoul(p, &endptr, 16);
			sum += static_cast<std::uint64_t>(v);
			p = endptr;
			if (p < end && *p == '\n')
			{
				++p;
			}
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}

	// std::from_chars (hex)
	{
		fast_io::timer t(u8"std_from_chars_hex");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = std::from_chars(p, end, v, 16);
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

	// fast_io core sto (hex) - scan_int_contiguous_none_simd_space_part_define_impl
	{
		fast_io::timer t(u8"fastio_scan_int_none_simd_hex (SIMT)");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = ::fast_io::details::scan_int_contiguous_none_simd_space_part_define_impl<16, char>(
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

	// fast_io char_digit_to_literal (hex)
	{
		fast_io::timer t(u8"fastio_char_digit_to_literal_hex");
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
				if (fast_io::details::char_digit_to_literal<16, char>(ch))
				{
					break;
				}
				v = (v << 4) + static_cast<std::uint64_t>(ch);
				++q;
			}
			sum += v;
			p = (q < end ? q + 1 : q);
		}
		std::uint64_t volatile sink = sum;
		(void)sink;
	}

	// fast_float (hex)
	{
		fast_io::timer t(u8"fast_float_from_chars_hex");
		std::uint64_t sum{};
		char const *p = begin;
		while (p < end)
		{
			std::uint64_t v{};
			auto res = fast_float::from_chars(p, end, v, 16);
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

	// Per-digit hex benchmarks: 1-digit up to theoretical max hexadecimal digits of uint64_t (16)
	{
		constexpr std::size_t max_hex_digits = 16;
		for (std::size_t digits = 1; digits <= max_hex_digits; ++digits)
		{
			auto buf_fixed = make_fixed_hex_numbers_buffer(digits, N);
			char const *fixed_begin = buf_fixed.data();
			char const *fixed_end = buf_fixed.data() + buf_fixed.size();

			fast_io::perrln("\n\nfixed_hex_digits=", digits, " lines=", N);

			{
				std::size_t lines{};
				for (char const *p = fixed_begin; p < fixed_end; ++p)
				{
					lines += (*p == '\n');
				}
				fast_io::perrln("lines=", lines);
			}

			// strtoul (hex) on fixed-width hex substrings
			{
				fast_io::timer t(u8"strtoul_hex_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					char *endptr{};
					auto v = std::strtoul(p, &endptr, 16);
					sum += static_cast<std::uint64_t>(v);
					p = endptr;
					if (p < fixed_end && *p == '\n')
					{
						++p;
					}
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}

			// std::from_chars (hex) on fixed-width hex substrings
			{
				fast_io::timer t(u8"std_from_chars_hex_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = std::from_chars(p, fixed_end, v, 16);
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

			// fast_io char_digit_to_literal (hex) on fixed-width hex substrings
			{
				fast_io::timer t(u8"fastio_char_digit_to_literal_hex_fixed");
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
						if (fast_io::details::char_digit_to_literal<16, char>(ch))
						{
							break;
						}
						v = (v << 4) + static_cast<std::uint64_t>(ch);
						++q;
					}
					sum += v;
					p = (q < fixed_end ? q + 1 : q);
				}
				std::uint64_t volatile sink = sum;
				(void)sink;
			}

			// fast_io core sto (hex) on fixed-width hex substrings
			{
				fast_io::timer t(u8"fastio_scan_int_none_simd_hex_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = ::fast_io::details::scan_int_contiguous_none_simd_space_part_define_impl<16, char>(
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

			// fast_float (hex) on fixed-width hex substrings
			{
				fast_io::timer t(u8"fast_float_from_chars_hex_fixed");
				std::uint64_t sum{};
				char const *p = fixed_begin;
				while (p < fixed_end)
				{
					std::uint64_t v{};
					auto res = fast_float::from_chars(p, fixed_end, v, 16);
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
