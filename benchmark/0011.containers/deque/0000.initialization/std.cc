#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <deque>

int main()
{
	fast_io::timer t(u8"std::deque");
	std::deque<std::size_t> vec(100000000);
}