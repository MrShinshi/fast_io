#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <fast_io_dsal/string.h>

template <typename T>
inline void test_copy_assignment()
{
	::fast_io::io::perr("=== copy assignment test ===\n");

	// Build source deque
	::fast_io::deque<T> src;
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		if constexpr (::std::same_as<T, ::std::size_t>)
		{
			src.push_back(i);
		}
		else
		{
			src.push_back(::fast_io::string(::fast_io::concat_fast_io(i)));
		}
	}

	// Build destination deque with garbage data
	::fast_io::deque<T> dst;
	for (::std::size_t i{}; i != 1234u; ++i)
	{
		if constexpr (::std::same_as<T, ::std::size_t>)
		{
			dst.push_back(999999u);
		}
		else
		{
			dst.emplace_back("garbage");
		}
	}

	// Perform copy assignment
	dst = src;

	// Check size
	if (dst.size() != src.size())
	{
		::fast_io::io::panic("ERROR: dst.size() != src.size() after copy assignment\n");
	}

	// Check element equality
	::std::size_t idx{};
	for (T const &e : dst)
	{
		if constexpr (::std::same_as<T, ::std::size_t>)
		{
			if (e != idx)
			{
				::fast_io::io::panicln("ERROR: dst element mismatch: ", e);
			}
		}
		else
		{
			::fast_io::string expected(::fast_io::concat_fast_io(idx));
			if (e != expected)
			{
				::fast_io::io::panicln("ERROR: dst string mismatch: ", e);
			}
		}
		++idx;
	}

	// Modify src to ensure deep copy
	if constexpr (::std::same_as<T, ::std::size_t>)
	{
		for (::std::size_t i{}; i != src.size(); ++i)
		{
			src[i] = src[i] + 1u;
		}
	}
	else
	{
		for (::std::size_t i{}; i != src.size(); ++i)
		{
			src[i].append("_changed");
		}
	}

	// dst must remain unchanged
	idx = 0u;
	for (T const &e : dst)
	{
		if constexpr (::std::same_as<T, ::std::size_t>)
		{
			if (e != idx)
			{
				::fast_io::io::panicln("ERROR: dst changed after modifying src: ", e);
			}
		}
		else
		{
			::fast_io::string expected(::fast_io::concat_fast_io(idx));
			if (e != expected)
			{
				::fast_io::io::panicln("ERROR: dst string changed after modifying src: ", e);
			}
		}
		++idx;
	}

	// Self-assignment test
	dst = dst;

	// Verify unchanged after self-assignment
	idx = 0u;
	for (T const &e : dst)
	{
		if constexpr (::std::same_as<T, ::std::size_t>)
		{
			if (e != idx)
			{
				::fast_io::io::panicln("ERROR: dst changed after self-assignment: ", e);
			}
		}
		else
		{
			::fast_io::string expected(::fast_io::concat_fast_io(idx));
			if (e != expected)
			{
				::fast_io::io::panicln("ERROR: dst string changed after self-assignment: ", e);
			}
		}
		++idx;
	}

	::fast_io::io::print("copy assignment test finished\n");
}

int main()
{
	test_copy_assignment<::std::size_t>();
	test_copy_assignment<::fast_io::string>();

	::fast_io::io::print("All copy assignment tests finished\n");
}
