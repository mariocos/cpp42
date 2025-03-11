#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# define NUM 100

class Brain
{
private:
	std::string thought[NUM];
public:
	Brain();
	Brain(Brain& cpy);
	~Brain();
	Brain& operator=(Brain& cpy);
	void	print_ideas(void);
	void	set_ideas(std::string new_thought);
};



#endif