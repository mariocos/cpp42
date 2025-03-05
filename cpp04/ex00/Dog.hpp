#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog();
	Dog(Dog& cpy);
	~Dog();
	Dog& operator=(Dog& cpy);
	void	makeSound(void)const;
};

#endif