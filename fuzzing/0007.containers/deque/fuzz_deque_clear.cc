#include <fast_io_dsal/deque.h>
#include <deque>
#include <cstddef>
#include <cstdint>
#include <ranges>

extern "C" int LLVMFuzzerTestOneInput(uint8_t const* data, size_t size)
{
    // Require large inputs to trigger growth/balancing
    if (size < 4096)
        return 0;

    ::fast_io::deque<std::size_t> dq;
    std::deque<std::size_t> ref;

    for (size_t i{}; i != size; ++i)
    {
        uint8_t raw = data[i];
        uint8_t op = raw % 6u;  // 6 operations
        std::size_t value = i;

        bool allow_clear =
            dq.size() >= 4096 || (raw == 0xFF);  
            // 1/256 chance of early clear

        switch (op)
        {
        case 0: // push_back
            dq.push_back(value);
            ref.push_back(value);
            break;

        case 1: // push_front
            dq.push_front(value);
            ref.push_front(value);
            break;

        case 2: // pop_back
            if (!ref.empty())
            {
                dq.pop_back();
                ref.pop_back();
            }
            break;

        case 3: // pop_front
            if (!ref.empty())
            {
                dq.pop_front();
                ref.pop_front();
            }
            break;

        case 4: // clear()
            if (allow_clear)
            {
                dq.clear();
                ref.clear();
            }
            break;

        case 5: // clear_destroy()
            if (allow_clear)
            {
                dq.clear_destroy();
                ref.clear();
            }
            break;
        }
    }

    // Validate correctness
    if (dq.size() != ref.size())
        __builtin_trap();

    if (!std::ranges::equal(dq, ref))
        __builtin_trap();

    return 0;
}
