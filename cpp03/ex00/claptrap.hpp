#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class claptrap
{
private:
	/* data */
	std::string	name;
	int		hp;
	int		ep;
	int		ac;
public:
	claptrap();
	claptrap(std::string name);
	~claptrap();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

claptrap::claptrap()
{
	std::cout << "construCTINNNNNGGGGG\n";
}

claptrap::claptrap(std::string nname)
{
	std::cout << "named constructinggg\n";
	name = nname;
}

claptrap::~claptrap()
{
}








#endif