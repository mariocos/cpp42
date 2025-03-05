#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	/* data */
	std::string type;
public:
	Animal();
	Animal(Animal& cpy);
	virtual	~Animal();
	Animal&	operator=(Animal& cpy);
	std::string	getType(void)const;
	virtual void	makeSound(void)const;
};

#endif