#include "scavtrap.hpp"

scavtrap::scavtrap() : claptrap()
{
	std::cout << "default constructor called for scavtrap\n";
	ep = SCAV_EP;
	hp = SCAV_HP;
	ac = SCAV_AC;
}

scavtrap::scavtrap(std::string nname) : claptrap(nname)
{
	std::cout << nname << " named constructing scavtrap\n";
	ep = SCAV_EP;
	hp = SCAV_HP;
	ac = SCAV_AC;
}

scavtrap::scavtrap(scavtrap& cpy) : claptrap(cpy.name)
{
	std::cout << "calling scav copy constructor\n";
	*this = cpy;
}

scavtrap::~scavtrap()
{
	std::cout << name << " is being oblitareted\n";
}

scavtrap&	scavtrap::operator=(scavtrap& cpy)
{
	std::cout << "scav copy assignment operator called\n";
	if (&cpy != this)
	{
		ac = cpy.ac;
		hp = cpy.hp;
		ep = cpy.ep;
	}
	return (*this);
}

void	scavtrap::attack(std::string target)
{
	if (hp < 1)
	{
		std::cout << "scavtrap "<< name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << "scavtrap " << name << " is out of energy and cant attack\n";
		return ;
	}
	std::cout << "scavtrap " << name << " is attacking " << target << " doing " << this->ac << " amount of damage\n";
}

void	scavtrap::guardGate(void)
{
	if (hp < 1)
	{
		std::cout << "scavtrap "<< name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << "scavtrap " << name << " is out of energy and cant enter gate mode\n";
		return ;
	}
	std::cout << "scavtrap " << name << " is now in gate keeper MODE\n";
}
