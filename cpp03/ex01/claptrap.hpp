#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

# define HP 10
# define EP 10
# define AC 0


class claptrap
{
protected:
	/* data */
	std::string	name;
	int		hp;
	int		ep;
	int		ac;
public:
	claptrap();
	claptrap(std::string name);
	claptrap(claptrap& cpy);
	~claptrap();
	claptrap&	operator=(claptrap& cpy);
	std::string	getname(void);
	void		setname(std::string nname);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif