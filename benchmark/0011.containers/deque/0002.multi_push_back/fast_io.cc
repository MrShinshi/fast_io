#include <fast_io_dsal/deque.h>
namespace test
{
template <typename T>
using vector = ::fast_io::deque<T>;
}
#define BENCH_VECTOR_COMMENT_STRING u8"fast_io::deque<T>"
#include "main.h"
