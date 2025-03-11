#include "Cat.hpp"
#include "Dog.hpp"
#include "Animal.hpp"
#include <iostream>

int main()
{
	std::cout << "creating an animal array with cats adn dogs\n";
	Animal	*barn[] =
	{
		new Dog(),
		new Dog(),
		new Dog(),
		new Cat(),
		new Cat(),
		new Cat(),
	};

	std::cout << "creating a john and john deep copy\n";
	Cat *john = new Cat();
	john->set_ideas("sentience is painfull.");
	Cat	*john_cpy = new Cat();
	john->print_ideas();
	john_cpy->print_ideas();
	delete john;
	delete john_cpy;
	std::cout << "deleteing the animals in the animal array\n";
	for (int i = 0; i < 6; i++)
	{
		delete barn[i];
	}
}