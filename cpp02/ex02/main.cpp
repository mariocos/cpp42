#include "fixed.hpp"

int main( void ) {
	fixed a;
	fixed const	b(fixed(5.05f) * fixed(2));
	std::cout << b << "b\n";
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << fixed::max(a, b) << std::endl;
	return 0;
}
