#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <cstddef>

int main()
{
	::fast_io::deque<::std::size_t> dq{30zu, 40zu, 20zu, 10zu};
	auto dq2(dq);
	::std::sort(dq.begin(), dq.end());
	::std::sort(dq2.rbegin(), dq2.rend());
	::fast_io::out_buf_type obf(::fast_io::out());
	using namespace ::fast_io::iomnp;
	print(obf, "dq:\n");
	for (auto const &e : dq)
	{
		println(obf, e);
	}
	print(obf, "\ndq2:\n");
	for (auto const &e : dq2)
	{
		println(obf, e);
	}
}
