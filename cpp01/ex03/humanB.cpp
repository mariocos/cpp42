#include "humanB.hpp"

HumanB::HumanB(std::string name):_name(name){}

HumanB::~HumanB()
{
}

void	HumanB::attack(void)
{
	if (_weapon)
		std::cout << _name << " attacks with their " << _weapon->get_type() << "\n";
	else
		std::cout << _name << " attacks with their poor hands\n";
}

void	HumanB::set_weapon(Weapon& gun)
{
	_weapon = &gun;
}
