#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "animal default constructor being called\n";
}

Animal::Animal(Animal& cpy)
{
	std::cout << "animal copy constructor called\n";
	*this = cpy;
}

Animal::~Animal()
{
	std::cout << "animal destructor being called\n";
}


Animal&	Animal::operator=(Animal& cpy)
{
	std::cout << "anima copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.getType();
	}
	return (*this);
}

std::string	Animal::getType(void)const
{
	return (type);
}

void	Animal::makeSound(void)const
{
	std::cout << "i dont know what sound to make\n";
}
