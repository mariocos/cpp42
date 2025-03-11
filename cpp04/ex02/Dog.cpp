#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain)
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
	delete brain;
}

Dog&	Dog::operator=(Dog& cpy)
{
	std::cout << "Dog copy assignment operator called\n";
	if (this != &cpy)
	{
		type = cpy.getType();
	}
	return (*this);
}

void	Dog::makeSound(void)const
{
	std::cout << "Barf\n";
}

void	Dog::print_ideas(void)
{
	brain->print_ideas();
}

void	Dog::set_ideas(std::string new_thought)
{
	brain->set_ideas(new_thought);
}
