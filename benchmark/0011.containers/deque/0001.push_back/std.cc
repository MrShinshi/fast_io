#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <deque>

int main()
{
	fast_io::timer tm(u8"std::deque::push_back");
	std::deque<std::size_t> vec;
	constexpr std::size_t n{100000000};
	for (std::size_t i{}; i != n; ++i)
	{
		vec.push_back(i);
	}
}
