#include "fixed.hpp"

void	fixed::setRawBits(int const set)
{
	this->value = set;
}

int	fixed::GetRawBits(void)const
{
	std::cout << "calling getrawbits\n";
	return (value);
}

fixed&	fixed::operator=(const fixed& cpy)
{
	std::cout << "this one\n";
	if (this != &cpy)
	{
		value = cpy.GetRawBits();
	}
	return(*this);
}

fixed::fixed()
{
	std::cout << "you created a var congrats!\n";
	value = 0;
}


fixed::fixed(const fixed& cpy)
{
	std::cout << "im copy constructing\n";
	value = cpy.value;
}

fixed::~fixed()
{
	std::cout << "im destructing!\n";
}

std::ostream&	operator<<(std::ostream& out, const fixed& c_fixed)
{
	out<<c_fixed.toFloat();
	return (out);
}


fixed::fixed(const int ivar)
{
	std::cout << "constructing with int\n";
	value = ivar << ratio;
}

fixed::fixed(const float fvar)
{
	std::cout << "constructing with float\n";
	value = (int)roundf(fvar * (1<<ratio));
}

float	fixed::toFloat(void)const
{
	return ((float)value / (float)(1<<ratio));
}

int		fixed::toInt(void)const
{
	return ((int)(value >> ratio));
}
