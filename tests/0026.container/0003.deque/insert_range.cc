#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <deque>
#include <vector>
namespace
{
inline void test_insert_range_index()
{
	::fast_io::io::perr("=== deque insert_range_index test ===\n");

	using T = ::std::size_t;
	::fast_io::deque<T> dq;
	::std::deque<T> ref;

	// Fill initial data
	for (::std::size_t i{}; i != 200u; ++i)
	{
		dq.push_back(i);
		ref.push_back(i);
	}

	// Helper to compare dq and ref
	auto check_equal = [&](auto const &msg) {
		if (dq.size() != ref.size())
		{
			::fast_io::io::panicln("ERROR: size mismatch: ", msg);
		}
		for (::std::size_t i{}; i != dq.size(); ++i)
		{
			if (dq[i] != ref[i])
			{
				::fast_io::io::panicln("ERROR: value mismatch at index ", i, " : ", msg);
			}
		}
	};

	// Test ranges
	::std::vector<T> rg1{1000, 1001, 1002, 1003, 1004};
	::std::vector<T> rg2{2000, 2001, 2002};
	::std::vector<T> rg3{3000};

	// Insert at front
	{
		dq.insert_range_index(0, rg1);
		ref.insert(ref.begin(), rg1.begin(), rg1.end());
		check_equal("insert at front");
	}

	// Insert at middle
	{
		::std::size_t pos{dq.size() / 2};
		dq.insert_range_index(pos, rg2);
		ref.insert(ref.begin() + pos, rg2.begin(), rg2.end());
		check_equal("insert at middle");
	}

	// Insert at back
	{
		::std::size_t pos{dq.size()};
		dq.insert_range_index(pos, rg3);
		ref.insert(ref.end(), rg3.begin(), rg3.end());
		check_equal("insert at back");
	}

	// Randomized insertions
	for (::std::size_t iter{}; iter != 200u; ++iter)
	{
		::std::size_t pos = iter % (dq.size() + 1);
		::std::vector<T> rg{iter + 5000, iter + 5001};

		dq.insert_range_index(pos, rg);
		ref.insert(ref.begin() + pos, rg.begin(), rg.end());

		check_equal("randomized insert");
	}

	::fast_io::io::print("deque insert_range_index test finished\n");
}
} // namespace

int main()
{
	test_insert_range_index();
}