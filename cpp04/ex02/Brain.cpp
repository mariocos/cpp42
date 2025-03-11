#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < NUM; i++)
		thought[i] = "mmmmmmmmmh";
}

Brain::Brain(Brain& cpy)
{
	std::cout << "brain copy constructor called\n";
	*this = cpy;
}

Brain::~Brain()
{
}

Brain&	Brain::operator=(Brain& cpy)
{
	if (this != &cpy)
	{
		for (int i = 0; i < NUM; i++)
		{
			this->thought[i] = cpy.thought[i];
		}
	}
	return (*this);
}

void	Brain::print_ideas(void)
{
	for (int i = 0; i < NUM; i++)
		std::cout << thought[i];
}

void	Brain::set_ideas(std::string new_thought)
{
	for (int i = 0; i < NUM; i++)
		thought[i] = new_thought;
}