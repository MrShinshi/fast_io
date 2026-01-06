#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
    ::fast_io::io::perr("=== deque(size_type n) test ===\n");

    constexpr ::std::size_t n{4096u};
    ::fast_io::deque<::std::size_t> dq(n);

    if (dq.size() != n)
    {
        ::fast_io::io::panic("ERROR: dq.size() != n\n");
    }

    // All elements must be default constructed (0 for size_t)
    for (auto const& e : dq)
    {
        if (e != 0u)
        {
            ::fast_io::io::panicln("ERROR: default constructed element != 0: ", e);
        }
    }

    ::fast_io::io::print("deque(size_type n) test finished\n");
}
