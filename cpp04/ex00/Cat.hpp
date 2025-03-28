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

#endif