#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "cat default constructor called\n";
}

Cat::Cat(Cat& cpy) : Animal(cpy)
{
	std::cout << "cat copy constructor being called\n";
	*this = cpy;
}

Cat::~Cat()
{
	std::cout << "cat destructor called\n";
}

Cat&	Cat::operator=(Cat& cpy)
{
	std::cout << "cat copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.getType();
	}
	return (*this);
}

void	Cat::makeSound(void)const
{
	std::cout << "MEOWF\n";
}