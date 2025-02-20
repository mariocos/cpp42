#ifndef ANIMAL_HPP
#define ANIMA_HPP

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
	std::string	gettype(void)const;
	virtual void	makeSound(void)const;
};

#endif