#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	/* data */
	std::string type;
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal& cpy);
	virtual	~WrongAnimal();
	WrongAnimal&	operator=(WrongAnimal& cpy);
	std::string	getType(void)const;
	virtual void	makeSound(void)const;
};

#endif