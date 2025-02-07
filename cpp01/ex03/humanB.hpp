#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "weapon.hpp"

class HumanB
{
private:
	/* data */
	std::string	_name;
	Weapon*		_weapon;
public:
	HumanB(std::string name);
	~HumanB();
	void	attack(void);
	void	set_weapon(Weapon& gun);
};




#endif