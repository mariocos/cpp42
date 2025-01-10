#include "horde.hpp"
#include "zombie.hpp"
#include <iostream>

int main(void)
{
	Zombie	*horde;

	horde = zombieHorde(15, "joe");
	delete (horde);
}