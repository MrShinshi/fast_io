#include <fast_io.h>
#include <fast_io_dsal/bitvec.h>

int main()
{
	::fast_io::bitvec bv;

	// Build initial pattern: 0 1 0 1 0 1 0 1 0 1
	for (::std::size_t i{}; i != 10; ++i)
	{
		bv.push_back((i & 1u) != 0u);
	}

	using namespace ::fast_io::iomnp;
	print("Initial bitvec:\n", bv, "\nExpected:\n0101010101\n\n");

	// Range to insert
	bool arr[4]{1, 0, 1, 1};

	auto bv2{bv};
	bv2.append_range(arr);

	print("After apend_range({1,0,1,1}):\n", bv2,
		  "\nExpected:\n01010101011011\n");
#if 0
    auto bv3{bv};
	bv3.insert_index(3, 4, true);
    print("bv3:\n",bv3, "\n\n");

	// Insert at index 3
	bv.insert_range_index(3, arr);

	print("After insert_range_index(3, {1,0,1,1}):\n", bv,
		  "\nExpected:\n01010111010101\n");

	// Expected result:
	// Initial: 0 1 0 1 0 1 0 1 0 1
	// Insert at index 3: [1 0 1 1]
	// Result: 0 1 0 1 0 1 1 1 0 1 0 1 0 1
#endif
}
