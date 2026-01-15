// deque_erase_fuzz.cc
#include <cstddef>
#include <cstdint>
#include <deque>
#include <vector>

#include <source_location>
#include <fast_io.h>
#include <fast_io_dsal/deque.h>

using T = std::size_t;

// Check equality between fast_io::deque and std::deque
static void check_equal(::fast_io::deque<T> const &dq,
						::std::deque<T> const &ref)
{
	if (dq.size() != ref.size())
	{
		__builtin_trap(); // mismatch: size
	}

	for (std::size_t i{}; i != dq.size(); ++i)
	{
		if (dq[i] != ref[i])
		{
			__builtin_trap(); // mismatch: value
		}
	}
}

// Map a byte to an operation kind
enum class OpKind : uint8_t
{
	PushBack = 0,
	PushFront = 1,
	EraseIndex = 2,
	EraseRangeIter = 3,
	// you can add more later
};

extern "C" int LLVMFuzzerTestOneInput(uint8_t const *data, std::size_t size)
{
	::fast_io::deque<T> dq;
	::std::deque<T> ref;

	// We interpret the input as a stream of small commands.
	// Each command may consume 1~3 bytes depending on the op.
	std::size_t i = 0;
	while (i < size)
	{
		uint8_t op_raw = data[i++] % 4; // we currently have 4 ops
		OpKind op = static_cast<OpKind>(op_raw);

		switch (op)
		{
		case OpKind::PushBack:
		{
			if (i >= size)
			{
				break;
			}
			// use the next byte as low bits of the value
			T v = static_cast<T>(data[i++]);
			dq.push_back(v);
			ref.push_back(v);
			break;
		}
		case OpKind::PushFront:
		{
			if (i >= size)
			{
				break;
			}
			T v = static_cast<T>(data[i++]);
			dq.push_front(v);
			ref.push_front(v);
			break;
		}
		case OpKind::EraseIndex:
		{
			if (dq.empty())
			{
				break;
			}

			if (i >= size)
			{
				break;
			}
			std::size_t pos = static_cast<std::size_t>(data[i++]);
			if (!dq.empty())
			{
				pos %= dq.size();
				dq.erase_index(pos);
				ref.erase(ref.begin() + static_cast<std::ptrdiff_t>(pos));
			}
			break;
		}
		case OpKind::EraseRangeIter:
		{
			if (dq.empty())
			{
				break;
			}

			if (i + 1 > size) // need at least 1 byte
			{
				break;
			}

			std::size_t n = dq.size();
			if (n == 0)
			{
				break;
			}

			// choose two indices from bytes
			std::size_t a = static_cast<std::size_t>(data[i++]) % n;
			std::size_t b = static_cast<std::size_t>(data[i++ % size]) % (n + 1);

			std::size_t first_idx = (a < b ? a : b);
			std::size_t last_idx = (a < b ? b : a);

			if (last_idx > n)
			{
				last_idx = n;
			}
			if (first_idx > last_idx)
			{
				first_idx = last_idx;
			}
			if (first_idx == last_idx)
			{
				break; // empty range, skip
			}

			auto dq_first = dq.begin() + static_cast<std::ptrdiff_t>(first_idx);
			auto dq_last = dq.begin() + static_cast<std::ptrdiff_t>(last_idx);
			auto ref_first = ref.begin() + static_cast<std::ptrdiff_t>(first_idx);
			auto ref_last = ref.begin() + static_cast<std::ptrdiff_t>(last_idx);

			dq.erase(dq_first, dq_last);
			ref.erase(ref_first, ref_last);
			break;
		}
		}

		// After each operation, verify dq == ref
		check_equal(dq, ref);
	}

	return 0;
}
