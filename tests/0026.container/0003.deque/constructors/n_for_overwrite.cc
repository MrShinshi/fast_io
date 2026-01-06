#include <fast_io.h>
#include <fast_io_dsal/deque.h>

int main()
{
    ::fast_io::io::perr("=== deque(size_type n, for_overwrite_t) test ===\n");

    constexpr ::std::size_t n{4096u};
    ::fast_io::deque<::std::size_t> dq(n, ::fast_io::for_overwrite);

    if (dq.size() != n)
    {
        ::fast_io::io::panic("ERROR: dq.size() != n\n");
    }

    // Assign values to ensure iteration works and references are valid
    ::std::size_t value{};
    for (auto &e : dq)
    {
        e = value;
        ++value;
    }

    // Verify values were written correctly
    value = 0;
    for (auto const& e : dq)
    {
        if (e != value)
        {
            ::fast_io::io::panicln("ERROR: assigned value mismatch: ", e);
        }
        ++value;
    }

    if (value != n)
    {
        ::fast_io::io::panic("ERROR: iteration count != n\n");
    }

    ::fast_io::io::print("deque(size_type n, for_overwrite_t) test finished\n");
}
