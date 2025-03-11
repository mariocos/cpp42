#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain* brain;
public:
	Dog();
	Dog(Dog& cpy);
	~Dog();
	Dog& operator=(Dog& cpy);
	void	makeSound(void)const;
	void	print_ideas(void);
	void	set_ideas(std::string new_thought);
};

#endif