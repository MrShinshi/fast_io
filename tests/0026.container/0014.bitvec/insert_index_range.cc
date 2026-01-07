#include <fast_io.h>
#include <fast_io_dsal/bitvec.h>

int main()
{
	::fast_io::bitvec bv;

	// Build initial pattern: 0 1 0 1 0 1 0 1
	for (std::size_t i = 0; i < 8; ++i)
	{
		bv.push_back((i & 1u) != 0u);
	}

	using namespace ::fast_io::iomnp;
	print("Initial bitvec:\n", bv,"\nExpected:\n01010101\n\n");

	// Range to insert
	bool arr[4]{1, 0, 1, 1};

	// Insert at index 3
	bv.insert_range_index(3, arr);

	print("After insert_range_index(3, {1,0,1,1}):\n", bv,
		  "\nExpected:\n01010110101\n");

	// Expected result:
	// Initial: 0 1 0 1 0 1 0 1
	// Insert at index 3: [1 0 1 1]
	// Result: 0 1 0 1 0 1 1 0 1 0 1

	return 0;
}
