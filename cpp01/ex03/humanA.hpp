#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include "weapon.hpp"

class HumanA
{
private:
	/* data */
	std::string	_name;
	Weapon		_weapon;
	//HumanA();
public:
	HumanA(std::string name,  Weapon &weap);
	~HumanA();
	void	attack(void);
};



#endif