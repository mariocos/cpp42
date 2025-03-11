#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "Wrongcat default constructor called\n";
}

WrongCat::WrongCat(WrongCat& cpy) : WrongAnimal(cpy)
{
	std::cout << "Wrongcat copy constructor being called\n";
	*this = cpy;
}

WrongCat::~WrongCat()
{
	std::cout << "Wrongcat destructor called\n";
}

WrongCat&	WrongCat::operator=(WrongCat& cpy)
{
	std::cout << "Wrongcat copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.getType();
	}
	return (*this);
}

void	WrongCat::makeSound(void)const
{
	std::cout << "WrongMEOWF\n";
}