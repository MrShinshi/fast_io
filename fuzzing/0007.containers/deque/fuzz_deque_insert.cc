#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <deque>
#include <cstddef>
#include <cstdint>
#include <cstring>
#include <ranges>
#include <vector>

extern "C" int LLVMFuzzerTestOneInput(uint8_t const *data, size_t size)
{
	::fast_io::deque<std::size_t> dq;
	std::deque<std::size_t> ref;

	for (size_t i{}; i != size; ++i)
	{
		uint8_t b = data[i];

		uint8_t op = b & 0x3u;             // 4 operations
		std::size_t len = (b >> 2) & 0x7u; // insert 0–7 elements

		// Always valid position: [0, size]
		std::size_t pos = dq.size() == 0 ? 0 : (static_cast<std::size_t>(b) * 37u) % (dq.size() + 1);

		// Build deterministic range
		std::vector<std::size_t> rg;
		rg.reserve(len);
		for (std::size_t j{}; j < len; ++j)
		{
			rg.push_back(i * 1315423911ull + j);
		}

		switch (op)
		{
		case 0: // insert_range_index
		{
			dq.insert_range_index(pos, rg);
			ref.insert(ref.begin() + pos, rg.begin(), rg.end());
			break;
		}

		case 1: // insert_range using iterator
		{
			auto it = dq.insert_range(dq.cbegin() + pos, rg);
			(void)it;
			ref.insert(ref.begin() + pos, rg.begin(), rg.end());
			break;
		}

		case 2: // erase single element (to keep sizes bounded)
		{
			if (!ref.empty())
			{
				std::size_t p = pos % ref.size();
				dq.erase_index(p);
				ref.erase(ref.begin() + p);
			}
			break;
		}

		case 3: // erase small range
		{
			if (!ref.empty())
			{
				std::size_t p = pos % ref.size();
				std::size_t rlen = len % (ref.size() - p);
				dq.erase_index(p, p + rlen);
				ref.erase(ref.begin() + p, ref.begin() + p + rlen);
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
	}

	return 0;
}
