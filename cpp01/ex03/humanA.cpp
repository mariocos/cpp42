#include "humanA.hpp"
#include "weapon.hpp"

HumanA::HumanA(std::string name, Weapon& weap):_name(name), _weapon(weap){};

HumanA::~HumanA()
{
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _weapon.get_type() << "\n";
}
