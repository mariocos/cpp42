#ifndef CONTACTS_HPP
# define CONTACTS_HPP

#include <iostream>
#include <cctype>

class contact
{
public:
	contact();
	~contact();
	std::string	get_param(int code);
	void	set_param(int code, std::string str);

private:
	/* data */
	std::string	first_name;
	std::string	last_name;
	std::string	nbr;
	std::string	nick;
	std::string secret;
};

#endif