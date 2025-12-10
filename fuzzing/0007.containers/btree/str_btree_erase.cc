#include <fast_io_dsal/str_btree_set.h>
#include <fast_io.h>
#include <cstdint>
#include <fast_io_dsal/string_view.h>
#include <fast_io_dsal/string.h>

extern "C" int LLVMFuzzerTestOneInput(uint8_t const* data, size_t size) {
    ::fast_io::str_btree_set bset;

    // Interpret bytes as operations
    for (size_t i = 0; i < size;) {
        uint8_t op = data[i++] % 3; // 0=insert, 1=erase, 2=find
        if (i >= size) break;
        uint8_t len = data[i++] % 8; // small string length
        if (i + len > size) break;

        ::fast_io::string_view key(reinterpret_cast<char const*>(data + i), len);
        i += len;

        switch (op) {
            case 0:
                bset.insert_key(key);
                break;
            case 1:
                bset.erase_key(key);
                break;
            case 2:
                (void)bset.find(key);
                break;
        }
    }

    // Optional: check invariants
    // e.g. iterate forward/backward, ensure sorted order
    ::fast_io::string prev;
    for (auto const e : bset) {
        if (!prev.empty()) {
            if (!(prev < e)) ::fast_io::fast_terminate(); // invariant violation
        }
        prev.assign(e);
    }

    return 0;
}

