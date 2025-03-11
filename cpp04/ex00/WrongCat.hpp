#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat& cpy);
	~WrongCat();
	WrongCat& operator=(WrongCat& cpy);
	void	makeSound(void)const;
};

#endif