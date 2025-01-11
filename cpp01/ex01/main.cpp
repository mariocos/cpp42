#include "horde.hpp"
#include "zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie	*horde;

	std::cout << "a horde of 2 joes is about to exist\n";
	horde = zombieHorde(2, "joe");
	delete[] horde;
	std::cout << "im gonna make a horde of 3 without a name\n";
	horde = zombieHorde(3, "");
	delete[] horde;
	std::cout << "A horde of -2 joes is coming to life\n";
	horde = zombieHorde(-2, "joe");
	delete[] horde;
}