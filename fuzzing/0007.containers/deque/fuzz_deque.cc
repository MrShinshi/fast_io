#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <deque>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <ranges>

extern "C" int LLVMFuzzerTestOneInput(uint8_t const *data, size_t size)
{
	::fast_io::deque<std::size_t> dq;
	std::deque<std::size_t> ref;

	// Interpret input as a sequence of operations
	for (size_t i{}; i != size; ++i)
	{
		uint8_t op = data[i] & 0x3u; // 4 operations
		std::size_t value = i;       // deterministic, stable

		switch (op)
		{
		case 0: // push_back

			dq.push_back(value);
			ref.push_back(value);
			break;

		case 1: // push_front

			dq.push_front(value);
			ref.push_front(value);
			break;

		case 2: // pop_back
			if (!ref.empty())
			{

				dq.pop_back();
				ref.pop_back();
			}
			break;

		case 3: // pop_front
			if (!ref.empty())
			{

				dq.pop_front();
				ref.pop_front();
			}
			break;
		}
	}

	// Validate correctness
	if (dq.size() != ref.size())
	{
		__builtin_trap();
	}
	if (!std::ranges::equal(dq, ref))
	{
		__builtin_trap();
	}
	return 0;
}
