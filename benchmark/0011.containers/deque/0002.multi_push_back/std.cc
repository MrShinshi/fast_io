#include <deque>
#include <cstdint>
namespace test
{
template <typename T>
using vector = ::std::deque<T>;
}
#define BENCH_VECTOR_COMMENT_STRING u8"std::deque<T>"
#include "main.h"