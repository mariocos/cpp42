#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
private:
	/* data */
	std::string	type;
public:
	Weapon(/* args */);
	~Weapon();
	const std::string&	get_type(void);
	void	set_type(std::string);
};









#endif