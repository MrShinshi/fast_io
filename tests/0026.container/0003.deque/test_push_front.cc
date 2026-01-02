#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
	::fast_io::deque<::std::uint_least32_t> dq;
	for(::std::uint_least32_t i{};i!=1048576u;++i)
	{
		dq.push_front(i);
	}

	static_assert(::std::random_access_iterator<decltype(dq.end())>);
#if 1
	for (auto const &e : dq)
	{
		::fast_io::io::println(e);
	}
#endif
}
