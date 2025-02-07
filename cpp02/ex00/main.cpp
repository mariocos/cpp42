#include "fixed.hpp"
#include <iostream>

int main( void )
{
	fixed a;
	fixed b( a );
	fixed c;
	c = b;
	std::cout << a.GetRawBits() << std::endl;
	std::cout << b.GetRawBits() << std::endl;
	std::cout << c.GetRawBits() << std::endl;
	return 0;
}