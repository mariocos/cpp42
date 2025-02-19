#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

# define FRAG_HP 100
# define FRAG_EP 100
# define FRAG_AC 30

class FragTrap : public ClapTrap
{
public:
	FragTrap();
	FragTrap(std::string _name);
	FragTrap(FragTrap &cpy);
	~FragTrap();
	FragTrap	&operator=(FragTrap& cpy);
	void	attack(std::string target);
	void	highFivesGuys(void);
};







#endif