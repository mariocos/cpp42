#include <iostream>
#include "zombie.hpp"

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
	std::cout << name << " is tired of living\n";
}

void	Zombie::announce(void)
{
	std::cout << get_param(1) << " : BraiiiiiiinnnzzzZ...\n";
}

std::string	Zombie::get_param(int code)
{
	switch (code)
	{
	case 1:
		return (name);
		break;
	default:
		break;
	}
	return ("");
}


void	Zombie::set_param(int code, std::string value)
{
	switch (code)
	{
	case 1:
		name = value;
		break;
	
	default:
		break;
	}
}
