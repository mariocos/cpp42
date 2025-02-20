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

Dog::Dog()
{
	std::cout << "Dog default constructor called\n";
}

Dog::Dog(Dog& cpy) : Animal(cpy)
{
	std::cout << "Dog copy constructor being called\n";
	*this = cpy;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog&	Dog::operator=(Dog& cpy)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.gettype();
	}
	return (*this);
}

void	Dog::makeSound(void)const
{
	std::cout << "Barf\n";
}

#endif