#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
	::fast_io::io::perr("=== clear_destroy() test ===\n");

	::fast_io::deque<::std::size_t> dq;

	// Fill with enough elements to force growth
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		dq.push_back(i);
	}

	// First clear() — keep memory but reset state
	dq.clear();

	// Validate empty state after clear()
	if (!dq.is_empty())
	{
		::fast_io::io::panic("ERROR: dq.is_empty() == false after clear()\n");
	}
	if (dq.size() != 0u)
	{
		::fast_io::io::panic("ERROR: dq.size() != 0 after clear()\n");
	}
	for (auto const &e : dq)
	{
		::fast_io::io::panicln("ERROR: iterated element after clear(): ", e);
	}

	// Now clear_destroy() — free all memory
	dq.clear_destroy();

	// Validate empty state after clear_destroy()
	if (!dq.is_empty())
	{
		::fast_io::io::panic("ERROR: dq.is_empty() == false after clear_destroy()\n");
	}
	if (dq.size() != 0u)
	{
		::fast_io::io::panic("ERROR: dq.size() != 0 after clear_destroy()\n");
	}
	for (auto const &e : dq)
	{
		::fast_io::io::panicln("ERROR: iterated element after clear_destroy(): ", e);
	}

	// Reuse the deque — must reinitialize cleanly
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		dq.push_front(i);
	}

	// Iterate to ensure no crash and correct behavior
	for (auto const &e : dq)
	{
		::fast_io::io::println(e);
	}

	::fast_io::io::print("clear_destroy() test finished\n");
}
