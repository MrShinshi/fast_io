#include <fast_io.h>
#include <fast_io_dsal/bitvec.h>

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

	::fast_io::io::print("All bitvec tests finished\n");
}
