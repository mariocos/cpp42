#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "claptrap.hpp"

# define SCAV_HP 100
# define SCAV_EP 50
# define SCAV_AC 20

class scavtrap : public claptrap
{
public:
	scavtrap();
	scavtrap(std::string _name);
	scavtrap(scavtrap &cpy);
	~scavtrap();
	scavtrap	&operator=(scavtrap &cpy);
	void	attack(std::string target);
	void	guardGate();
};


#endif