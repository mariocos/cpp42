#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain* brain;
public:
	Cat();
	Cat(Cat& cpy);
	~Cat();
	Cat& operator=(Cat& cpy);
	void	makeSound(void)const;
	void	print_ideas(void);
	void	set_ideas(std::string new_thought);
};

#endif