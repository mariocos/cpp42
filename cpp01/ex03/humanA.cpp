#include "humanA.hpp"
#include "weapon.hpp"

HumanA::HumanA(std::string name, Weapon weap)
{
}

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their " << Weapon << "\n";
}
