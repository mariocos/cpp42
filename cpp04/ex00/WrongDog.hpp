#ifndef WRONGDOG_HPP
#define WRONGDOG_HPP

#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
public:
	WrongDog();
	WrongDog(WrongDog& cpy);
	~WrongDog();
	WrongDog& operator=(WrongDog& cpy);
	void	makeSound(void)const;
};

#endif