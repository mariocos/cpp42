#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : claptrap()
{
	std::cout << "default constructor called for ScavTrap\n";
	ep = SCAV_EP;
	hp = SCAV_HP;
	ac = SCAV_AC;
}

ScavTrap::ScavTrap(std::string nname) : claptrap(nname)
{
	std::cout << nname << " named constructing ScavTrap\n";
	ep = SCAV_EP;
	hp = SCAV_HP;
	ac = SCAV_AC;
}

ScavTrap::ScavTrap(ScavTrap& cpy) : claptrap(cpy.name)
{
	std::cout << "calling scav copy constructor\n";
	*this = cpy;
}

ScavTrap::~ScavTrap()
{
	std::cout << name << " is being oblitareted\n";
}

ScavTrap&	ScavTrap::operator=(ScavTrap& cpy)
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

void	ScavTrap::attack(std::string target)
{
	if (hp < 1)
	{
		std::cout << "ScavTrap "<< name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << "ScavTrap " << name << " is out of energy and cant attack\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " is attacking " << target << " doing " << this->ac << " amount of damage\n";
}

void	ScavTrap::guardGate(void)
{
	if (hp < 1)
	{
		std::cout << "ScavTrap "<< name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << "ScavTrap " << name << " is out of energy and cant enter gate mode\n";
		return ;
	}
	std::cout << "ScavTrap " << name << " is now in gate keeper MODE\n";
}
