#ifndef fIXED_HPP
#define	fIXED_HPP


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
	/*ex02 part*/
	bool	operator>(const fixed& v_fixed)const;
	bool	operator>=(const fixed& v_fixed)const;
	bool	operator<(const fixed& v_fixed)const;
	bool	operator<=(const fixed& v_fixed)const;
	bool	operator==(const fixed& v_fixed)const;
	bool	operator!=(const fixed& v_fixed)const;
	fixed	operator+(const fixed& v_fixed)const;
	fixed	operator-(const fixed& v_fixed)const;
	fixed	operator*(const fixed& v_fixed)const;
	fixed	operator/(const fixed& v_fixed)const;
	fixed	&operator++();
	fixed	&operator--();
	fixed	operator++(int);
	fixed	operator--(int);
	static const fixed&	min(const fixed& nbr1, const fixed& nbr2);
	static fixed&		min(fixed& nbr1, fixed& nbr2);
	static const fixed&	max(const fixed& nbr1, const fixed& nbr2);
	static fixed&		max(fixed& nbr1, fixed& nbr2);
};

std::ostream&	operator<<(std::ostream& out, const fixed& c_fixed);




#endif