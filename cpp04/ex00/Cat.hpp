#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	Cat(Cat& cpy);
	~Cat();
	Cat& operator=(Cat& cpy);
	void	makeSound(void)const;
};

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
		type = cpy.gettype();
	}
	return (*this);
}

void	Cat::makeSound(void)const
{
	std::cout << "MEOWF\n";
}

#endif