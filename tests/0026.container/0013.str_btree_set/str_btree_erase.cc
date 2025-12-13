#include <fast_io.h>
#include <fast_io_dsal/str_btree_set.h>
#include <fast_io_dsal/string_view.h>

int main() {
    // Use a small keys_number to make underflow/merge easier to trigger
    ::fast_io::containers::basic_str_btree_set<char,
        ::fast_io::native_global_allocator, 4> bset;

    // Dataset: left child has 2 keys, right child has 2 keys, root has 1 key
    constexpr ::fast_io::string_view dataset[]{
        ::fast_io::string_view("a"),
        ::fast_io::string_view("b"),   // left child
        ::fast_io::string_view("x"),
        ::fast_io::string_view("y"),   // right child
        ::fast_io::string_view("m")    // root internal key
    };

    // Insert all keys
    for (auto const& e : dataset) {
        bset.insert_key(e);
    }

    // Print tree contents before erase
    ::fast_io::io::print("\nTree contents before erase:\n");
    for (auto const& e : bset) {
        ::fast_io::io::println(e);
    }

    // Erase the internal key "m" to trigger merge/underflow
    ::fast_io::io::print("\nErasing 'm'...\n");
    bset.erase_key("m");

    // Print tree contents after erase
    ::fast_io::io::print("\nTree contents after erase:\n");
    for (auto const& e : bset) {
        ::fast_io::io::println(e);
    }

    // Print whether the tree is empty
    ::fast_io::io::println("\nbset.is_empty(): ", bset.is_empty());
}
