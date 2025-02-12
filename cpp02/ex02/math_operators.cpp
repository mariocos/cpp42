#include "fixed.hpp"

fixed	fixed::operator+(const fixed& v_fixed)const
{
	fixed	ret;

	ret.setRawBits(GetRawBits() + v_fixed.GetRawBits());
	return (ret);
}

fixed	fixed::operator-(const fixed& v_fixed)const
{
	fixed ret;

	ret.setRawBits(GetRawBits() - v_fixed.GetRawBits());
	return (ret);
}

fixed	fixed::operator*(const fixed& v_fixed)const
{
	std::cout << "multiplying\n";
	fixed ret;

	ret.setRawBits((GetRawBits() * v_fixed.GetRawBits()) >> ratio);
	return (ret);
}

fixed	fixed::operator/(const fixed& v_fixed)const
{
	fixed ret;

	ret.setRawBits(GetRawBits() / v_fixed.GetRawBits());
	return (ret);
}

fixed& fixed::operator++()
{
	value++;
	return (*this);
}

fixed&	fixed::operator--()
{
	value--;
	return (*this);
}

fixed	fixed::operator++(int)
{
	fixed ret = *this;

	this->value++;
	return (ret);
}

fixed	fixed::operator--(int)
{
	fixed ret = *this;

	this->value--;
	return (ret);
}

const fixed&	fixed::min(const fixed& nbr1, const fixed& nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

fixed&	fixed::min(fixed& nbr1, fixed& nbr2)
{
	if (nbr1 < nbr2)
		return (nbr1);
	return (nbr2);
}

const fixed&	fixed::max(const fixed& nbr1, const fixed& nbr2)
{
	if (nbr1 < nbr2)
		return (nbr2);
	return (nbr1);
}


fixed&	fixed::max(fixed& nbr1, fixed& nbr2)
{
	if (nbr1 < nbr2)
		return (nbr2);
	return (nbr1);
}