#include <iostream>
#include "horde.hpp"
#include "zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zombo_horde;

	if (N <= 0)
		return (NULL);
	if (name.empty())
		name = "Carl";
	zombo_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombo_horde[i].set_param(1, name);
		zombo_horde[i].announce();
	}
	return (zombo_horde);
}