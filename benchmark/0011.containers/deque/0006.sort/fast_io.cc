#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <fast_io_dsal/deque.h>
#include <algorithm>
#include <random>

int main()
{
	constexpr std::size_t n{1000000};
	::std::mt19937_64 eng;
	::std::uniform_int_distribution<::std::size_t> dis(0, SIZE_MAX);

	::fast_io::timer tm(u8"fast_io::deque");
	::fast_io::deque<std::size_t> deq;
	{
		::fast_io::timer tm1(u8"push_back");
		for (std::size_t i{}; i != n; ++i)
		{
			deq.push_back(dis(eng));
		}
	}
	{
		::fast_io::timer tm1(u8"sort");
		::std::ranges::sort(deq);
	}
	::std::size_t sum{};
	{
		::fast_io::timer tm1(u8"loop");
		for (auto const &e : deq)
		{
			sum += e;
		}
	}
	::fast_io::io::perrln("sum=", sum);
}
