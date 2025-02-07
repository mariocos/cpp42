#ifndef FIXED_HPP
#define	FIXED_HPP


#include <iostream>

class fixed
{
private:
	/* data */
	static const int	ratio = 8;
	int					value;
public:
	fixed(/* args */);//default constructor 
	fixed(fixed& cpy);//copy constructor
	/* operator overloader */
	fixed&	operator=(const fixed& cpy);
	~fixed();//destructor
	/* set bits and print bits missing */
	int	GetRawBits(void)const;
	void setRawBits(int const raw);
};

#endif