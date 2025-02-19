#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

# define HP 10
# define EP 10
# define AC 0


class ClapTrap
{
private:
	/* data */
	std::string	name;
	int		hp;
	int		ep;
	int		ac;
public:
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(ClapTrap& cpy);
	~ClapTrap();
	ClapTrap&	operator=(ClapTrap& cpy);
	std::string	getname(void);
	void		setname(std::string nname);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif