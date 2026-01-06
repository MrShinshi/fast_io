#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <fast_io_dsal/deque.h>

int main()
{
	fast_io::timer t(u8"fast_io::deque");
	::fast_io::deque<std::size_t> deq(100000000);
}