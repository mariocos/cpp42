#ifndef FIXED_HPP
#define	FIXED_HPP


#include <iostream>
#include <cmath>

class fixed
{
private:
	/* data */
	static const int	ratio = 8;
	int					value;
public:
	fixed();//default constructor 
	fixed(const int ivar);
	fixed(const float fvar);
	fixed(const fixed& cpy);//copy constructor
	/* operator overloader */
	fixed&	operator=(const fixed& cpy);
	~fixed();//destructor
	/* member */
	int	GetRawBits(void)const;
	void setRawBits(int const raw);
	float	toFloat(void)const;
	int		toInt(void)const;
};

std::ostream&	operator<<(std::ostream& out, const fixed& c_fixed);




#endif