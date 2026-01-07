#include <fast_io.h>
#include <fast_io_dsal/bitvec.h>
#include <fast_io_dsal/vector.h>

inline void test_bitvec_basic()
{
	::fast_io::io::perr("=== bitvec basic test ===\n");

	::fast_io::bitvec bv;

	// Push 4096 alternating bits
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		bv.push_back((i & 1u) != 0u);
	}

	if (bv.size() != 4096u)
	{
		::fast_io::io::panic("ERROR: size mismatch after push_back\n");
	}

	// Verify alternating pattern
	for (::std::size_t i{}; i != 4096u; ++i)
	{
		bool expected = (i & 1u) != 0u;
		if (bv.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: test() mismatch at index ", i);
		}
	}

	::fast_io::io::print("bitvec basic test finished\n");
}

inline void test_bitvec_set_reset()
{
	::fast_io::io::perr("=== bitvec set/reset test ===\n");

	::fast_io::bitvec bv;

	// Push 100 bits of 0
	for (::std::size_t i{}; i != 100u; ++i)
	{
		bv.push_back(false);
	}

	// Set even bits to 1
	for (::std::size_t i{}; i < 100u; i += 2u)
	{
		bv.set_unchecked(i, true);
	}

	// Verify
	for (::std::size_t i{}; i != 100u; ++i)
	{
		bool expected = (i % 2u == 0u);
		if (bv.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: set_unchecked mismatch at index ", i);
		}
	}

	// Reset all bits
	for (::std::size_t i{}; i != 100u; ++i)
	{
		bv.reset_unchecked(i);
	}

	for (::std::size_t i{}; i != 100u; ++i)
	{
		if (bv.test(i) != false)
		{
			::fast_io::io::panicln("ERROR: reset_unchecked mismatch at index ", i);
		}
	}

	::fast_io::io::print("bitvec set/reset test finished\n");
}

inline void test_bitvec_front_back()
{
	::fast_io::io::perr("=== bitvec front/back test ===\n");

	::fast_io::bitvec bv;

	// Push 10 bits: 0 1 0 1 0 1 0 1 0 1
	for (::std::size_t i{}; i != 10u; ++i)
	{
		bv.push_back((i & 1u) != 0u);
	}

	// Verify front bit (should be 0)
	if (bv.test_front() != false)
	{
		::fast_io::io::panic("ERROR: test_front mismatch (expected 0)\n");
	}

	// Verify back bit (should be 1)
	if (bv.test_back() != true)
	{
		::fast_io::io::panic("ERROR: test_back mismatch (expected 1)\n");
	}

	// Set front to 1
	bv.set_front(true);
	if (bv.test_front() != true)
	{
		::fast_io::io::panic("ERROR: set_front failed (expected 1)\n");
	}

	// Reset front to 0
	bv.reset_front();
	if (bv.test_front() != false)
	{
		::fast_io::io::panic("ERROR: reset_front failed (expected 0)\n");
	}

	// Set back to 0
	bv.set_back(false);
	if (bv.test_back() != false)
	{
		::fast_io::io::panic("ERROR: set_back failed (expected 0)\n");
	}

	// Reset back to 0 again (should remain 0)
	bv.reset_back();
	if (bv.test_back() != false)
	{
		::fast_io::io::panic("ERROR: reset_back failed (expected 0)\n");
	}

	// Now set front/back using unchecked versions
	bv.set_front_unchecked(true);
	if (bv.test_front() != true)
	{
		::fast_io::io::panic("ERROR: set_front_unchecked failed\n");
	}

	bv.set_back_unchecked(true);
	if (bv.test_back() != true)
	{
		::fast_io::io::panic("ERROR: set_back_unchecked failed\n");
	}

	// Reset both using unchecked versions
	bv.reset_front_unchecked();
	if (bv.test_front() != false)
	{
		::fast_io::io::panic("ERROR: reset_front_unchecked failed\n");
	}

	bv.reset_back_unchecked();
	if (bv.test_back() != false)
	{
		::fast_io::io::panic("ERROR: reset_back_unchecked failed\n");
	}

	::fast_io::io::print("bitvec front/back test finished\n");
}

inline void test_bitvec_pop_back()
{
	::fast_io::io::perr("=== bitvec pop_back test ===\n");

	::fast_io::bitvec bv;

	for (::std::size_t i{}; i != 128u; ++i)
	{
		bv.push_back((i & 1u) != 0u);
	}

	for (::std::size_t i{}; i != 128u; ++i)
	{
		bool expected = ((128u - 1u - i) & 1u) != 0u;
		bool popped = bv.pop_back();
		if (popped != expected)
		{
			::fast_io::io::panicln("ERROR: pop_back mismatch at iteration ", i);
		}
	}

	if (bv.size() != 0u)
	{
		::fast_io::io::panic("ERROR: size not zero after popping all bits\n");
	}

	::fast_io::io::print("bitvec pop_back test finished\n");
}

inline void test_bitvec_copy_constructor()
{
	::fast_io::io::perr("=== bitvec copy constructor test ===\n");

	::fast_io::bitvec src;

	for (::std::size_t i{}; i != 2048u; ++i)
	{
		src.push_back((i & 3u) == 1u);
	}

	::fast_io::bitvec dst(src);

	if (dst.size() != src.size())
	{
		::fast_io::io::panic("ERROR: size mismatch in copy constructor\n");
	}

	for (::std::size_t i{}; i != src.size(); ++i)
	{
		if (dst.test(i) != src.test(i))
		{
			::fast_io::io::panicln("ERROR: copy constructor mismatch at index ", i);
		}
	}

	// Modify src to ensure deep copy
	for (::std::size_t i{}; i != src.size(); ++i)
	{
		src.set_unchecked(i, !src.test(i));
	}

	// dst must remain unchanged
	for (::std::size_t i{}; i != dst.size(); ++i)
	{
		bool expected = ((i & 3u) == 1u);
		if (dst.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: deep copy violated at index ", i);
		}
	}

	::fast_io::io::print("bitvec copy constructor test finished\n");
}

inline void test_bitvec_copy_assignment()
{
	::fast_io::io::perr("=== bitvec copy assignment test ===\n");

	::fast_io::bitvec src;
	::fast_io::bitvec dst;

	// Use a valid mask: (i & 7u) can equal 2u
	for (::std::size_t i{}; i != 3000u; ++i)
	{
		src.push_back((i & 7u) == 2u);
	}

	// Fill dst with garbage first
	for (::std::size_t i{}; i != 777u; ++i)
	{
		dst.push_back(true);
	}

	dst = src;

	if (dst.size() != src.size())
	{
		::fast_io::io::panic("ERROR: size mismatch in copy assignment\n");
	}

	for (::std::size_t i{}; i != src.size(); ++i)
	{
		if (dst.test(i) != src.test(i))
		{
			::fast_io::io::panicln("ERROR: copy assignment mismatch at index ", i);
		}
	}

	// Modify src to ensure deep copy
	for (::std::size_t i{}; i != src.size(); ++i)
	{
		src.set_unchecked(i, !src.test(i));
	}

	// dst must remain unchanged
	for (::std::size_t i{}; i != dst.size(); ++i)
	{
		bool expected = ((i & 7u) == 2u);
		if (dst.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: deep copy violated in assignment at index ", i);
		}
	}

	// Self-assignment
	dst = dst;

	for (::std::size_t i{}; i != dst.size(); ++i)
	{
		bool expected = ((i & 7u) == 2u);
		if (dst.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: self-assignment changed data at index ", i);
		}
	}

	::fast_io::io::print("bitvec copy assignment test finished\n");
}

inline void test_bitvec_move()
{
	::fast_io::io::perr("=== bitvec move test ===\n");

	::fast_io::bitvec src;

	for (::std::size_t i{}; i != 1024u; ++i)
	{
		src.push_back((i & 7u) == 3u);
	}

	::fast_io::bitvec moved(::std::move(src));

	if (moved.size() != 1024u)
	{
		::fast_io::io::panic("ERROR: size mismatch in move constructor\n");
	}

	for (::std::size_t i{}; i != 1024u; ++i)
	{
		bool expected = ((i & 7u) == 3u);
		if (moved.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: move constructor mismatch at index ", i);
		}
	}

	// src must be empty
	if (src.size() != 0u)
	{
		::fast_io::io::panic("ERROR: moved-from bitvec not empty\n");
	}

	::fast_io::io::print("bitvec move test finished\n");
}

inline void test_bitvec_flip()
{
	::fast_io::io::perr("=== bitvec flip test ===\n");

	::fast_io::bitvec bv;

	// Push 64 bits: 0 1 0 1 0 1 ...
	for (::std::size_t i{}; i != 64u; ++i)
	{
		bv.push_back((i & 1u) != 0u);
	}

	// Flip all bits using checked flip()
	for (::std::size_t i{}; i != 64u; ++i)
	{
		bv.flip(i);
	}

	// Verify: all bits should now be inverted
	for (::std::size_t i{}; i != 64u; ++i)
	{
		bool expected = ((i & 1u) == 0u); // original was (i&1)!=0, so flipped
		if (bv.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: flip() mismatch at index ", i);
		}
	}

	// Flip again using unchecked version → should restore original pattern
	for (::std::size_t i{}; i != 64u; ++i)
	{
		bv.flip_unchecked(i);
	}

	for (::std::size_t i{}; i != 64u; ++i)
	{
		bool expected = (i & 1u) != 0u;
		if (bv.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: flip_unchecked() mismatch at index ", i);
		}
	}

	// Test flip_front and flip_back
	// Current front = 0, back = 1
	if (bv.test_front() != false)
	{
		::fast_io::io::panic("ERROR: test_front mismatch before flip_front\n");
	}
	if (bv.test_back() != true)
	{
		::fast_io::io::panic("ERROR: test_back mismatch before flip_back\n");
	}

	bv.flip_front();
	if (bv.test_front() != true)
	{
		::fast_io::io::panic("ERROR: flip_front failed\n");
	}

	bv.flip_back();
	if (bv.test_back() != false)
	{
		::fast_io::io::panic("ERROR: flip_back failed\n");
	}

	// Now test unchecked versions
	bv.flip_front_unchecked();
	if (bv.test_front() != false)
	{
		::fast_io::io::panic("ERROR: flip_front_unchecked failed\n");
	}

	bv.flip_back_unchecked();
	if (bv.test_back() != true)
	{
		::fast_io::io::panic("ERROR: flip_back_unchecked failed\n");
	}

	::fast_io::io::print("bitvec flip test finished\n");
}

inline void test_bitvec_reserve_and_push_back_unchecked()
{
	::fast_io::io::perr("=== bitvec reserve + push_back_unchecked test ===\n");

	::fast_io::bitvec bv;

	// Reserve space for 5000 bits
	bv.reserve(5000);

	if (bv.capacity() < 5000)
	{
		::fast_io::io::panic("ERROR: reserve did not increase capacity correctly\n");
	}

	// Now push bits WITHOUT triggering reallocation
	// Use push_back_unchecked since we know capacity is sufficient
	for (::std::size_t i{}; i != 5000u; ++i)
	{
		bv.push_back_unchecked((i & 1u) != 0u);
	}

	if (bv.size() != 5000u)
	{
		::fast_io::io::panic("ERROR: size mismatch after push_back_unchecked\n");
	}

	// Verify pattern
	for (::std::size_t i{}; i != 5000u; ++i)
	{
		bool expected = (i & 1u) != 0u;
		if (bv.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: push_back_unchecked mismatch at index ", i);
		}
	}

	::fast_io::io::print("bitvec reserve + push_back_unchecked test finished\n");
}

inline void test_bitvec_all_operations()
{
	::fast_io::io::perr("=== bitvec _all operations test ===\n");

	::fast_io::bitvec bv;

	// Create a bitvec with a size that forces a partial byte
	constexpr std::size_t N = 100; // 100 bits → 12 full bytes + 4 bits
	for (std::size_t i{}; i != N; ++i)
	{
		bv.push_back((i & 1u) != 0u); // alternating pattern
	}

	// --- Test reset_all() ---
	bv.reset_all();

	for (std::size_t i{}; i != N; ++i)
	{
		if (bv.test(i) != false)
		{
			::fast_io::io::panicln("ERROR: reset_all mismatch at index ", i);
		}
	}

	// --- Test set_all() ---
	bv.set_all();

	for (std::size_t i{}; i != N; ++i)
	{
		if (bv.test(i) != true)
		{
			::fast_io::io::panicln("ERROR: set_all mismatch at index ", i);
		}
	}

	// --- Test flip_all() ---
	// After flip_all(), all bits should become 0
	bv.flip_all();

	for (std::size_t i{}; i != N; ++i)
	{
		if (bv.test(i) != false)
		{
			::fast_io::io::panicln("ERROR: flip_all mismatch at index ", i);
		}
	}

	// --- Test flip_all() again ---
	// Should restore all bits to 1
	bv.flip_all();

	for (std::size_t i{}; i != N; ++i)
	{
		if (bv.test(i) != true)
		{
			::fast_io::io::panicln("ERROR: flip_all second pass mismatch at index ", i);
		}
	}

	// --- Ensure size and capacity unchanged ---
	if (bv.size() != N)
	{
		::fast_io::io::panic("ERROR: size changed after _all operations\n");
	}

	::fast_io::io::print("bitvec _all operations test finished\n");
}

inline void test_bitvec_bitops()
{
	::fast_io::io::perr("=== bitvec bit operations test ===\n");

	::fast_io::bitvec a;
	::fast_io::bitvec b;

	for (::std::size_t i{}; i != 256u; ++i)
	{
		a.push_back((i & 1u) != 0u); // 010101...
		b.push_back((i & 3u) == 2u); // 0010001000...
	}

	// --- operator& ---
	::fast_io::bitvec c = a & b;
	for (::std::size_t i{}; i != 256u; ++i)
	{
		bool expected = ((i & 1u) != 0u) && ((i & 3u) == 2u);
		if (c.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: operator& mismatch at index ", i);
		}
	}

	// --- operator| ---
	::fast_io::bitvec d = a | b;
	for (::std::size_t i{}; i != 256u; ++i)
	{
		bool expected = ((i & 1u) != 0u) || ((i & 3u) == 2u);
		if (d.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: operator| mismatch at index ", i);
		}
	}

	// --- operator^ ---
	::fast_io::bitvec e = a ^ b;
	for (::std::size_t i{}; i != 256u; ++i)
	{
		bool expected = ((i & 1u) != 0u) ^ ((i & 3u) == 2u);
		if (e.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: operator^ mismatch at index ", i);
		}
	}

	// --- shifts ---
	::fast_io::bitvec f = a << 3;
	for (::std::size_t i{}; i + 3 < 256u; ++i)
	{
		if (f.test(i + 3) != a.test(i))
		{
			::fast_io::io::panicln("ERROR: operator<< mismatch at index ", i);
		}
	}

	::fast_io::bitvec g = a >> 5;
	for (::std::size_t i{}; i + 5 < 256u; ++i)
	{
		if (g.test(i) != a.test(i + 5))
		{
			::fast_io::io::panicln("ERROR: operator>> mismatch at index ", i);
		}
	}

	// --- rotations (only if assign ops exist) ---
	{
		::fast_io::bitvec r1 = bitvec_rotl(a, 7);
		::fast_io::bitvec r2 = bitvec_rotr(a, 7);

		for (::std::size_t i{}; i != 256u; ++i)
		{
			if (r1.test(i) != a.test((i + 256u - 7u) % 256u))
			{
				::fast_io::io::panicln("ERROR: rotl mismatch at index ", i);
			}

			if (r2.test(i) != a.test((i + 7u) % 256u))
			{
				::fast_io::io::panicln("ERROR: rotr mismatch at index ", i);
			}
		}
	}

	// --- bit_floor / bit_ceil ---
	{
		::fast_io::bitvec single;
		single.push_back(false);
		single.push_back(false);
		single.push_back(true); // 100b

		::fast_io::bitvec bf = bitvec_bit_floor(single);
		::fast_io::bitvec bc = bitvec_bit_ceil(single);

		if (!bf.test(2) || bf.test(1) || bf.test(0))
		{
			::fast_io::io::panic("ERROR: bit_floor incorrect\n");
		}

		if (!bc.test(2) || bc.test(1) || bc.test(0))
		{
			::fast_io::io::panic("ERROR: bit_ceil incorrect\n");
		}
	}

	::fast_io::io::print("bitvec bit operations test finished\n");
}


inline void test_bitvec_init_list_and_range()
{
	::fast_io::io::perr("=== bitvec initializer_list + range constructor test ===\n");

	using ::fast_io::bitvec;
	using ::fast_io::vector;

	// --- initializer_list test ---
	bitvec ilv{true, false, true, true, false, false, true};

	if (ilv.size() != 7)
	{
		::fast_io::io::panic("ERROR: initializer_list size mismatch\n");
	}

	bool expected_il[7]{1, 0, 1, 1, 0, 0, 1};
	for (::std::size_t i{}; i != 7; ++i)
	{
		if (ilv.test(i) != expected_il[i])
		{
			::fast_io::io::panicln("ERROR: initializer_list mismatch at index ", i);
		}
	}

	// --- range constructor test ---
	vector<int> vec;
	vec.reserve(10);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(1);
	vec.push_back(0);
	vec.push_back(1);

	bitvec rv(::fast_io::freestanding::from_range, vec);

	if (rv.size() != vec.size())
	{
		::fast_io::io::panic("ERROR: range constructor size mismatch\n");
	}

	for (::std::size_t i{}; i != vec.size(); ++i)
	{
		if (rv.test(i) != static_cast<bool>(vec[i]))
		{
			::fast_io::io::panicln("ERROR: range constructor mismatch at index ", i);
		}
	}

	::fast_io::io::print("bitvec initializer_list + range constructor test finished\n");
}
#if 0
inline void test_bitvec_insert_and_erase()
{
	::fast_io::io::perr("=== bitvec insert/erase test ===\n");

	using ::fast_io::bitvec;

	bitvec bv;

	// ------------------------------------------------------------
	// 1. Start with a known pattern
	// ------------------------------------------------------------
	for (std::size_t i{}; i != 16; ++i)
	{
		bv.push_back((i & 1u) != 0u); // 010101...
	}

	// Verify initial pattern
	for (std::size_t i{}; i != 16; ++i)
	{
		bool expected = (i & 1u) != 0u;
		if (bv.test(i) != expected)
		{
			::fast_io::io::panicln("ERROR: initial pattern mismatch at ", i);
		}
	}

	// ------------------------------------------------------------
	// 2. insert_index: insert 3 zeros at position 5
	// ------------------------------------------------------------
	{
		bitvec ref = bv;               // reference copy
		ref.insert_index(5, 3, false); // expected result

		bv.insert_index(5, 3, false); // actual result

		if (bv.size() != ref.size())
		{
			::fast_io::io::panic("ERROR: insert_index size mismatch\n");
		}

		for (std::size_t i{}; i != bv.size(); ++i)
		{
			if (bv.test(i) != ref.test(i))
			{
				::fast_io::io::panicln("ERROR: insert_index mismatch at ", i);
			}
		}
	}

	// ------------------------------------------------------------
	// 3. insert_range_index with sized range
	// ------------------------------------------------------------
	{
		bool arr[4]{1, 0, 1, 1};

		bitvec ref = bv;                // reference before insertion
		ref.insert_range_index(2, arr); // expected

		bv.insert_range_index(2, arr); // actual

		if (bv.size() != ref.size())
		{
			::fast_io::io::panic("ERROR: insert_range_index size mismatch\n");
		}

		for (std::size_t i{}; i != bv.size(); ++i)
		{
			if (bv.test(i) != ref.test(i))
			{
				::fast_io::io::panicln("ERROR: insert_range_index mismatch at ", i);
			}
		}
	}

	// ------------------------------------------------------------
	// 4. append_range
	// ------------------------------------------------------------
	{
		int tail[5]{1, 1, 0, 0, 1};

		bitvec ref = bv;
		ref.append_range(tail);

		bv.append_range(tail);

		if (bv.size() != ref.size())
		{
			::fast_io::io::panic("ERROR: append_range size mismatch\n");
		}

		for (std::size_t i{}; i != bv.size(); ++i)
		{
			if (bv.test(i) != ref.test(i))
			{
				::fast_io::io::panicln("ERROR: append_range mismatch at ", i);
			}
		}
	}

	// ------------------------------------------------------------
	// 5. erase_index: erase 4 bits starting at index 3
	// ------------------------------------------------------------
	{
		bitvec ref = bv;

		ref.erase_index(3, 4);

		bv.erase_index(3, 4);

		if (ref != bv)
		{
			::fast_io::io::panic("ERROR: content mismatch\n");
		}

		if (bv.size() != ref.size())
		{
			::fast_io::io::panic("ERROR: erase_index size mismatch\n");
		}

		for (std::size_t i{}; i != bv.size(); ++i)
		{
			if (bv.test(i) != ref.test(i))
			{
				::fast_io::io::panicln("ERROR: erase_index mismatch at ", i);
			}
		}
	}

	::fast_io::io::print("bitvec insert/erase test finished\n");
}


int main()
{
	test_bitvec_basic();
	test_bitvec_set_reset();
	test_bitvec_front_back();
	test_bitvec_pop_back();
	test_bitvec_copy_constructor();
	test_bitvec_copy_assignment();
	test_bitvec_move();
	test_bitvec_flip();
	test_bitvec_reserve_and_push_back_unchecked();
	test_bitvec_all_operations();
	test_bitvec_init_list_and_range();
	test_bitvec_bitops();
#if 0
	test_bitvec_insert_and_erase();
#endif
	::fast_io::io::print("All bitvec tests finished\n");
}
