#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Wronganimal default constructor being called\n";
}

WrongAnimal::WrongAnimal(WrongAnimal& cpy)
{
	std::cout << "Wronganimal copy constructor called\n";
	*this = cpy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Wronganimal destructor being called\n";
}


WrongAnimal&	WrongAnimal::operator=(WrongAnimal& cpy)
{
	std::cout << "Wronganimal copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.getType();
	}
	return (*this);
}

std::string	WrongAnimal::getType(void)const
{
	return (type);
}

void	WrongAnimal::makeSound(void)const
{
	std::cout << "i dont know what Wrong sound to make\n";
}
