#include "weopon.hpp"

weapon::weapon(/* args */)
{
}

weapon::~weapon()
{
}

const std::string&	weapon::get_type(void)
{
	return(type);
}

void	weapon::set_type(std::string new_type)
{
	if (new_type.empty())
	{
		std::cout << "please dont try to set the weopon type as empty\n";
		return ;
	}
	type = new_type;
}