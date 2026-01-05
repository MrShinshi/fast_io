#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <deque>

int main()
{
	fast_io::timer tm(u8"std::deque::push_back total");
	std::deque<std::size_t> deq;
	constexpr std::size_t n{100000000};
	fast_io::timer tm1(u8"std::deque::push_back");
	for (std::size_t i{}; i != n; ++i)
	{
		deq.push_back(i);
	}
}
