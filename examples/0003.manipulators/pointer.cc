#include <fast_io.h>
#include <memory>

class dummy_class
{
public:
	void dummy_method() noexcept
	{}
};

struct A
{
	virtual void f() noexcept
	{}
};

struct B
{
	virtual void g() noexcept
	{}
};

struct C : A, B
{
};

struct S
{
	int x;
	double y;
	int z;
};

struct VA
{
	int a;
};

struct VB : virtual VA
{
	int b;
};

using namespace fast_io::io;

void foo()
{}

int main()
{
	using namespace fast_io::mnp;

	int fd{3};
	int *ptr{::std::addressof(fd)};
	char const *ptr2 = "hello";

	void (C::*downcptr)() noexcept = &B::g;

	println(
		"funcvw(foo):", funcvw(foo),
		"\n"
		"pointervw(ptr):",
		pointervw(ptr),
		"\n"
		"handlevw(fd):",
		handlevw(fd),
		"\n"
		"handlevw(ptr):",
		handlevw(ptr),
		"\n"
		"pointervw(ptr2):",
		pointervw(ptr2),
		"\n"
		"dec(pointervw(ptr2)):",
		dec(pointervw(ptr2)),
		"\n"
		"os_c_str(ptr2):",
		os_c_str(ptr2),
		"\n"
		"methodvw(&dummy_class::dummy_method):",
		methodvw(&dummy_class::dummy_method),
		"\n"
		"dec(methodvw(&dummy_class::dummy_method)):",
		dec(methodvw(&dummy_class::dummy_method)),
		"\n"
		"methodvw(downcptr):",
		methodvw(downcptr),
		"\n"
		"fieldptrvw(&S::x):",
		fieldptrvw(&S::x),
		"\n"
		"fieldptrvw(&S::y):",
		fieldptrvw(&S::y),
		"\n"
		"fieldptrvw(&S::z):",
		fieldptrvw(&S::z),
		"\n"
		"fieldptrvw(&VB::b):",
		fieldptrvw(&VB::b),
		"\n"
		"fieldptrvw(&VA::a):",
		fieldptrvw(&VA::a));
}
/*
funcvw(foo):0x0000000102368570
pointervw(ptr):0x000000016da96e1c
handlevw(fd):3
handlevw(ptr):0x000000016da96e1c
pointervw(ptr2):0x0000000102369f0c
dec(pointervw(ptr2)):4332101388
os_c_str(ptr2):hello
methodvw(&dummy_class::dummy_method):0x0000000102369400+0x0
dec(methodvw(&dummy_class::dummy_method)):4332098560+0
methodvw(downcptr):0x0000000000000000+0x11
fieldptrvw(&S::x):0x0000000000000000
fieldptrvw(&S::y):0x0000000000000008
fieldptrvw(&S::z):0x0000000000000010
fieldptrvw(&VB::b):0x0000000000000008
fieldptrvw(&VA::a):0x0000000000000000
*/
