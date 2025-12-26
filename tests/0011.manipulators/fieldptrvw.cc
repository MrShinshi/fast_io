#include <fast_io.h>

struct S
{
	int x;
	double y;
	int z;
};
struct A
{
	int a;
};
struct B
{
	int b;
};
struct C : A, B
{}; // multiple inheritance

int main()
{
	using namespace ::fast_io::iomnp;
	println("&B::b = ", fieldptrvw(&B::b), "\n"
										   "&C::b = ",
			fieldptrvw(&C::b), "\n"
							   "&S::z = ",
			fieldptrvw(&S::z));
}
