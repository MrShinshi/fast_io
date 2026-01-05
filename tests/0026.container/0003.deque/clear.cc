#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
	::fast_io::io::perr("=== clear() test ===\n");

	::fast_io::deque<::std::size_t> dq;

	// Fill with enough elements to force growth
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		dq.push_back(i);
	}

	// Clear but keep memory
	dq.clear();

	// Validate empty state
	if (!dq.is_empty())
	{
		::fast_io::io::panic("ERROR: dq.is_empty() == false after clear()\n");
	}

	if (dq.size() != 0u)
	{
		::fast_io::io::panic("ERROR: dq.size() != 0 after clear()\n");
	}

	// Ensure iteration produces nothing
	for (auto const &e : dq)
	{
		::fast_io::io::panicln("ERROR: iterated element after clear(): ", e);
	}

	// Reuse the deque
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		dq.push_front(i);
	}

	// Iterate to ensure no crash
	for (auto const &e : dq)
	{
		::fast_io::io::println(e);
	}

	::fast_io::io::print("clear() test finished\n");
}
