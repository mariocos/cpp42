#include <iostream>
#include "zombie.hpp"

Zombie	*newZombie(std::string name)
{
	Zombie	*zombo = new(Zombie);


	if (name.empty())
		zombo->set_param(1, "carl");
	else
		zombo->set_param(1, name);
	return (zombo);
}

void randomChump(std::string name)
{
	Zombie zombo;

	if (name.empty())
		zombo.set_param(1, "joe");
	else
		zombo.set_param(1, name);
	zombo.announce();
}

int main(void)
{
	randomChump("vasco");
	Zombie	*zombo = newZombie("gnut");
	zombo->announce();
	delete(zombo);
}