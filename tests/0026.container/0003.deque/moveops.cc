#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
	::fast_io::io::perr("=== move() test ===\n");

	::fast_io::deque<::std::size_t> dq;

	// Fill with enough elements to force growth
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		dq.push_back(i);
	}

	// Move-construct
	::fast_io::deque<::std::size_t> dq2{::std::move(dq)};

	// dq must be empty after move
	if (!dq.is_empty())
	{
		::fast_io::io::panic("ERROR: moved-from dq is not empty\n");
	}
	if (dq.size() != 0u)
	{
		::fast_io::io::panic("ERROR: moved-from dq.size() != 0\n");
	}

	// dq2 must contain all elements
	::std::size_t expected{};
	for (auto const &e : dq2)
	{
		if (e != expected)
		{
			::fast_io::io::panicln("ERROR: dq2 element mismatch: ", e);
		}
		++expected;
	}

	// Now test move assignment
	::fast_io::deque<::std::size_t> dq3;

	for (::std::size_t i{}; i != 2048u; ++i)
	{
		dq3.push_front(i);
	}

	dq3 = ::std::move(dq2);

	// dq2 must be empty
	if (!dq2.is_empty())
	{
		::fast_io::io::panic("ERROR: moved-from dq2 is not empty after assignment\n");
	}

	// dq3 must contain the original dq2 contents
	expected = 0u;
	for (auto const &e : dq3)
	{
		if (e != expected)
		{
			::fast_io::io::panicln("ERROR: dq3 element mismatch: ", e);
		}
		++expected;
	}

	// Reuse dq2 after move
	for (::std::size_t i{}; i != 1024u; ++i)
	{
		dq2.push_back(i);
	}

	for (auto const &e : dq2)
	{
		::fast_io::io::println(e);
	}

	::fast_io::io::print("move() test finished\n");
}
