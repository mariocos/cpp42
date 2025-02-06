#ifndef WEOPON_HPP
#define WEOPON_HPP

#include <iostream>

class weapon
{
private:
	/* data */
	std::string	type;
public:
	weapon(/* args */);
	~weapon();
	const std::string&	get_type(void);
	void	set_type(std::string);
};









#endif