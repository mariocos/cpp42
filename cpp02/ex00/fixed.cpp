#include "fixed.hpp"

void	fixed::setRawBits(int const set)
{
	this->value = set;
}

int	fixed::GetRawBits(void)const
{
	return (value);
}

fixed&	fixed::operator=(const fixed& cpy)
{
	if (this != &cpy)
	{
		value = cpy.GetRawBits();
	}
	return(*this);
}

fixed::fixed(/* args */)
{
	std::cout << "you created a var congrats!\n";
	value = 0;
}

fixed::fixed(fixed& cpy)
{
	std::cout << "im copy constructing\n";
	value = cpy.value;
}

fixed::~fixed()
{
	std::cout << "im destructing!\n";
}
