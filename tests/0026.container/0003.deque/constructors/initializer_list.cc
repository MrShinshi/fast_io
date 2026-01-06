#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
    ::fast_io::io::perr("=== deque(initializer_list) test ===\n");

    ::fast_io::deque<::std::size_t> dq{1u, 2u, 3u, 4u, 5u};

    if (dq.size() != 5u)
    {
        ::fast_io::io::panic("ERROR: dq.size() != 5\n");
    }

    ::std::size_t expected{};
    for (auto const& e : dq)
    {
        ++expected;
        if (e != expected)
        {
            ::fast_io::io::panicln("ERROR: element mismatch: ", e);
        }
    }

    ::fast_io::io::print("deque(initializer_list) test finished\n");
}
