#include "ClapTrap.hpp"

/* constructors */
ClapTrap::ClapTrap() : hp(HP), ep(EP), ac(AC)
{
	std::cout << "default construCTINNNNNGGGGG\n";
}

ClapTrap::ClapTrap(ClapTrap& cpy)
{
	std::cout << "copy constructing\n";
	*this = cpy;
}

ClapTrap::ClapTrap(std::string nname) : hp(HP), ep(EP), ac(AC)
{
	std::cout << "named constructinggg\n";
	name = nname;
}

ClapTrap::~ClapTrap()
{
	std::cout << "destructing\n";
}

/* operator */

ClapTrap&	ClapTrap::operator=(ClapTrap& cpy)
{
	if (this != &cpy)
		name = cpy.getname();
	return (*this);
}

/* getters and setters */

std::string	ClapTrap::getname(void)
{
	return (name);
}

void	ClapTrap::setname(std::string nname)
{
	name = nname;
}

/* member functions */

void	ClapTrap::attack(const std::string& target)
{
	if (hp < 1)
	{
		std::cout << name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << name << " is out of energy and cant attack\n";
		return ;
	}
	std::cout << name << " is attacking " << target << " doing " << this->ac << " amount of damage\n";
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << name << " is taking " << amount << " of damage\n";
	hp -= amount;
	ep--;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (hp < 1)
	{
		std::cout << name << " is dead and cant do anything\n";
	}
	if (ep < 1)
	{
		std::cout << name << " is out of energy and cant repair\n";
		return ;
	}
	std::cout << name << " is going to repair itslef for " << amount << "\n";
	hp += amount;
	ep--;
}
