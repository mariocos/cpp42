#include <iostream>
#include <algorithm>
#include "horde.hpp"
#include "zombie.hpp"

Zombie	*zombieHorde( int N, std::string name )
{
	Zombie	*zombo_horde;

	if (N == 0)
		return (NULL);
	if (name.empty())
		name = "Carl";
	if (N < 0)
	{
		std::reverse(name.begin(), name.end());
		N *= -1;
	}
	zombo_horde = new Zombie[N];
	for (int i = 0; i < N; i++)
	{
		zombo_horde[i].set_param(1, name);
		zombo_horde[i].announce();
	}
	return (zombo_horde);
}