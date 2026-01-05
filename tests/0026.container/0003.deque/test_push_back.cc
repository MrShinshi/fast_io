#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
	::fast_io::deque<::std::size_t> dq;
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		dq.push_back(i);
	}

	for (auto const &e : dq)
	{
		::fast_io::io::println(e);
	}
}
