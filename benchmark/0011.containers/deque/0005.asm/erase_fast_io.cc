#include <fast_io_dsal/deque.h>
#include <cstdint>

template<typename T>
using test_deque = ::fast_io::deque<T>;

void erase_u16(
	test_deque<::std::uint_least16_t> &dq,
	decltype(dq.begin()) first,
	decltype(dq.begin()) last
)
{
	dq.erase(first,last);
}

void erase_u32(
	test_deque<::std::uint_least32_t> &dq,
	decltype(dq.begin()) first,
	decltype(dq.begin()) last
)
{
	dq.erase(first,last);
}

void erase_u64(
	test_deque<::std::uint_least64_t> &dq,
	decltype(dq.begin()) first,
	decltype(dq.begin()) last
)
{
	dq.erase(first,last);
}
