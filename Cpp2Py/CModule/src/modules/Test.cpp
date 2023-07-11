#include "Test.h"

Test::Test()
	:Test(0, 0)
{}

Test::Test(int x, int y)
	:x(x), y(y)
{
	DEBUG("Create");
}
