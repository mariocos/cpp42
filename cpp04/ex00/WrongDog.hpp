#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "Animal.hpp"

class WrongDog : public Animal
{
public:
	WrongDog();
	WrongDog(WrongDog& cpy);
	~WrongDog();
	WrongDog& operator=(WrongDog& cpy);
	void	makeSound(void)const;
};

#endif