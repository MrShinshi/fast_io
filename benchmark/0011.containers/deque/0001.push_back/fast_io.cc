#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <fast_io_dsal/deque.h>

int main()
{
	fast_io::timer tm(u8"fast_io::deque::push_back total");
	fast_io::deque<std::size_t> deq;
	constexpr std::size_t n{100000000};
	fast_io::timer tm1(u8"fast_io::deque::push_back");
	for (std::size_t i{}; i != n; ++i)
	{
		deq.emplace_back(i);
	}
}
