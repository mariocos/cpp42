#include "FragTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap	clap("Bob");
	ScavTrap	scav("Boby");
	FragTrap	frag1("Harl");
	FragTrap	frag2("Karen");

	frag2.highFivesGuys();
	for (int i = 0; i < FRAG_EP; i++)
	{
		frag1.attack(frag2.getname());
	}
	for (int i = 0; i < SCAV_EP; i++)
	{
		scav.attack(frag2.getname());
	}
	for (int i = 0; i < EP; i++)
	{
		clap.attack(frag2.getname());
	}
	frag1.attack(frag2.getname());
	scav.attack(frag2.getname());
	clap.attack(frag2.getname());
	frag2.attack(frag1.getname());
	frag2.attack(scav.getname());
	frag2.attack(clap.getname());
	return (0);
}