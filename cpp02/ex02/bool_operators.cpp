#include "fixed.hpp"

bool	fixed::operator>(const fixed& v_fixed)const
{
	return (GetRawBits() > v_fixed.GetRawBits());
}

bool	fixed::operator>=(const fixed& v_fixed)const
{
	return (GetRawBits() >= v_fixed.GetRawBits());
}

bool	fixed::operator<(const fixed& v_fixed)const
{
	return (GetRawBits() < v_fixed.GetRawBits());
}

bool	fixed::operator<=(const fixed& v_fixed)const
{
	return (GetRawBits() <= v_fixed.GetRawBits());
}

bool	fixed::operator==(const fixed& v_fixed)const
{
	return (GetRawBits() == v_fixed.GetRawBits());
}

bool	fixed::operator!=(const fixed& v_fixed)const
{
	return (GetRawBits() != v_fixed.GetRawBits());
}
