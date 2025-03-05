#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "Animal.hpp"

class WrongCat : public Animal
{
public:
	WrongCat();
	WrongCat(WrongCat& cpy);
	~WrongCat();
	WrongCat& operator=(WrongCat& cpy);
	void	makeSound(void)const;
};

#endif