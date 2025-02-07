#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class harl
{
private:
	/* data */
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	harl(/* args */);
	~harl();
	void	complain(std::string level);
};






#endif