#include <fast_io.h>
#include <fast_io_dsal/deque.h>
#include <fast_io_dsal/string_view.h>
#include <fast_io_dsal/string.h>

template<typename T>
inline void test_copy_constructor()
{
    ::fast_io::io::perr("=== copy constructor test for type ===\n");

    // Fill original deque
    ::fast_io::deque<T> dq;
    for (::std::size_t i{}; i != 4096u; ++i)
    {
        if constexpr(::std::same_as<T, ::std::size_t>)
        {
            dq.push_back(i);
        }
        else
        {
            dq.emplace_back(::fast_io::concat_fast_io(i));
        }
    }

    // Copy construct
    ::fast_io::deque<T> dq2(dq);

    // Size must match
    if (dq2.size() != dq.size())
    {
        ::fast_io::io::panic("ERROR: dq2.size() != dq.size() after copy construction\n");
    }

    // Elements must match
    ::std::size_t idx{};
    for (T const& e : dq2)
    {
        if constexpr(::std::same_as<T, ::std::size_t>)
        {
            if (e != idx)
            {
                ::fast_io::io::panicln("ERROR: dq2 element mismatch: ", e);
            }
        }
        else
        {
            ::fast_io::string expected(::fast_io::concat_fast_io(idx));
            if (e != expected)
            {
                ::fast_io::io::panicln("ERROR: dq2 string mismatch: ", e);
            }
        }
        ++idx;
    }

    // Modify original to ensure deep copy
    if constexpr(::std::same_as<T, ::std::size_t>)
    {
        for (auto & e : dq)
        {
            ++e;
        }
    }
    else
    {
        for (auto & e : dq)
        {
            e.append(::fast_io::u8cstring_view(u8"_changed"));
        }
    }

    // dq2 must remain unchanged
    idx = 0u;
    for (T const& e : dq2)
    {
        if constexpr(::std::same_as<T, ::std::size_t>)
        {
            if (e != idx)
            {
                ::fast_io::io::panicln("ERROR: dq2 changed after modifying dq: ", e);
            }
        }
        else
        {
            ::fast_io::string expected(::fast_io::concat_fast_io(idx));
            if (e != expected)
            {
                ::fast_io::io::panicln("ERROR: dq2 string changed after modifying dq: ", e);
            }
        }
        ++idx;
    }

    ::fast_io::io::print("copy constructor test finished\n");
}

int main()
{
    test_copy_constructor<::std::size_t>();
//    test_copy_constructor<::fast_io::string>();

    ::fast_io::io::print("All copy constructor tests finished\n");
}
