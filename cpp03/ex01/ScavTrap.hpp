#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_AC 20

class ScavTrap : public ClapTrap
{
public:
	ScavTrap();
	ScavTrap(std::string _name);
	ScavTrap(ScavTrap &cpy);
	~ScavTrap();
	ScavTrap	&operator=(ScavTrap &cpy);
	void	attack(std::string target);
	void	guardGate();
};


#endif