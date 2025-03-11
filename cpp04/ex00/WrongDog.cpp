#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal()
{
	std::cout << "WrongDog default constructor called\n";
}

WrongDog::WrongDog(WrongDog& cpy) : WrongAnimal(cpy)
{
	std::cout << "WrongDog copy constructor being called\n";
	*this = cpy;
}

WrongDog::~WrongDog()
{
	std::cout << "WrongDog destructor called\n";
}

WrongDog&	WrongDog::operator=(WrongDog& cpy)
{
	std::cout << "WrongDog copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.getType();
	}
	return (*this);
}

void	WrongDog::makeSound(void)const
{
	std::cout << "WrongBarf\n";
}
