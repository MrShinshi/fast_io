#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <fast_io_dsal/vector.h>

int main()
{
    ::fast_io::io::perr("=== deque(from_range_t, R) test ===\n");

    ::fast_io::vector<::std::size_t> vec;
    for (::std::size_t i{}; i != 4096u; ++i)
    {
        vec.push_back(i);
    }

    ::fast_io::deque<::std::size_t> dq(::fast_io::freestanding::from_range, vec);

    if (dq.size() != vec.size())
    {
        ::fast_io::io::panic("ERROR: dq.size() != vec.size()\n");
    }

    ::std::size_t idx{};
    for (auto const& e : dq)
    {
        if (e != vec[idx])
        {
            ::fast_io::io::panicln("ERROR: element mismatch: ", e);
        }
        ++idx;
    }

    ::fast_io::io::print("deque(from_range_t, R) test finished\n");
}
