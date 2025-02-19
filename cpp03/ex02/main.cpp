#include "scavtrap.hpp"

int	main(void)
{
	claptrap	clap("Bob");
	scavtrap	scav("Boby");

	scav.guardGate();
	for (int i = 0; i < EP; i++)
	{
		clap.attack(scav.getname());
	}
	clap.attack(scav.getname());
	scav.attack(clap.getname());
	return (0);
}