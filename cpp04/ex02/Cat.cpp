#include "Cat.hpp"

Cat::Cat() : Animal(), brain(new Brain)
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
	delete(brain);
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

void	Cat::print_ideas(void)
{
	brain->print_ideas();
}

void	Cat::set_ideas(std::string new_thought)
{
	brain->set_ideas(new_thought);
}