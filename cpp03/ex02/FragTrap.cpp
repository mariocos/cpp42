#include "ScavTrap.hpp"
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "default constructor called for ScavTrap\n";
	ep = FRAG_EP;
	hp = FRAG_HP;
	ac = FRAG_AC;
}

FragTrap::FragTrap(std::string nname) : ClapTrap(nname)
{
	std::cout << nname << " named constructing ScavTrap\n";
	ep = FRAG_EP;
	hp = FRAG_HP;
	ac = FRAG_AC;
}

FragTrap::FragTrap(FragTrap& cpy) : ClapTrap(cpy.name)
{
	std::cout << "calling scav copy constructor\n";
	*this = cpy;
}

FragTrap::~FragTrap()
{
	std::cout << name << " is being oblitareted\n";
}

FragTrap&	FragTrap::operator=(FragTrap& cpy)
{
	std::cout << "frag copy assignment operator called\n";
	if (&cpy != this)
	{
		ac = cpy.ac;
		hp = cpy.hp;
		ep = cpy.ep;
	}
	return (*this);
}

void	FragTrap::attack(std::string target)
{
	if (hp < 1)
	{
		std::cout << "FragTrap "<< name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << "FragTrap " << name << " is out of energy and cant attack\n";
		return ;
	}
	std::cout << "FragTrap " << name << " is attacking " << target << " doing " << this->ac << " amount of damage\n";
}

void	FragTrap::highFivesGuys(void)
{
	if (hp < 1)
	{
		std::cout << "FragTrap "<< name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << "FragTrap " << name << " is out of energy and cant look for highfives\n";
		return ;
	}
	std::cout << "WHAZAAA anyone want a high five????\n";
}
