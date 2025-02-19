#include "claptrap.hpp"

/* constructors */
claptrap::claptrap() : hp(HP), ep(EP), ac(AC)
{
	std::cout << "default construCTINNNNNGGGGG\n";
}

claptrap::claptrap(claptrap& cpy)
{
	std::cout << "copy constructing\n";
	*this = cpy;
}

claptrap::claptrap(std::string nname) : hp(HP), ep(EP), ac(AC)
{
	std::cout << "named constructinggg\n";
	name = nname;
}

claptrap::~claptrap()
{
	std::cout << "destructing\n";
}

/* operator */

claptrap&	claptrap::operator=(claptrap& cpy)
{
	if (this != &cpy)
		name = cpy.getname();
	return (*this);
}

/* getters and setters */

std::string	claptrap::getname(void)
{
	return (name);
}

void	claptrap::setname(std::string nname)
{
	name = nname;
}

/* member functions */

void	claptrap::attack(const std::string& target)
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

void	claptrap::takeDamage(unsigned int amount)
{
	std::cout << name << " is taking " << amount << " of damage\n";
	hp -= amount;
	ep--;
}

void	claptrap::beRepaired(unsigned int amount)
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
