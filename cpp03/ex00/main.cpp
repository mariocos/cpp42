#include "claptrap.hpp"

int	main(void)
{
	claptrap	clap1("tom");
	claptrap	clap2("jerry");

	for (int i = 0; i < EP; i++)
	{
		clap1.attack("Boby");
		clap2.takeDamage(0);
	}
	clap1.attack("Boby");
	clap2.beRepaired(0);
	return (0);
}