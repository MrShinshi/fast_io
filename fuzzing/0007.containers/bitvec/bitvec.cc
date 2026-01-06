#include<cstdint>
#include<fast_io_dsal/bitvec.h>

extern "C" int LLVMFuzzerTestOneInput(uint8_t const *data, size_t size)
{
	fast_io::bitvec bv;

	// Push all bits from input
	for (size_t i = 0; i != size; ++i)
	{
		bv.push_back((data[i] & 1) != 0);
	}

	if (bv.size() > 8)
	{
		// Save original bits 1..7
		bool saved[7];
		for (size_t i = 1; i != 8; ++i)
		{
			saved[i - 1] = bv.test(i);
		}

		// Mutate front bit
		bv.set_front_unchecked(true);

		// Check if bits 1..7 changed (they SHOULD NOT)
		for (size_t i = 1; i != 8; ++i)
		{
			if (bv.test(i) != saved[i - 1])
			{
				__builtin_trap(); // crash → libFuzzer finds bug
			}
		}
	}

	return 0;
}
