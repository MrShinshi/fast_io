#include <fast_io.h>
#include <fast_io_driver/timer.h>
#include <fast_io_dsal/vector.h>

int main()
{
	::fast_io::timer tm(u8"fast_io::vector reserve");
	::fast_io::vector<std::size_t> vec;
	constexpr std::size_t n{100000000};
	vec.reserve(n);
	{
		fast_io::timer tm1(u8"push_back");
		for (std::size_t i{}; i != n; ++i)
		{
			vec.push_back(i);
		}
	}
	::std::size_t sum{};
	{
		fast_io::timer tm1(u8"indexing loop");
		for (::std::size_t i{}, sz{vec.size()}; i != sz; ++i)
		{
			sum += vec[i];
		}
	}
	::fast_io::io::perrln("sum=", sum);
}
