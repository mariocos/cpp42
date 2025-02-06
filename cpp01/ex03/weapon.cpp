#include "weapon.hpp"

Weapon::Weapon(/* args */)
{
}

Weapon::~Weapon()
{
}

const std::string&	Weapon::get_type(void)
{
	return(type);
}

void	Weapon::set_type(std::string new_type)
{
	if (new_type.empty())
	{
		std::cout << "please dont try to set the weapon type as empty\n";
		return ;
	}
	type = new_type;
}