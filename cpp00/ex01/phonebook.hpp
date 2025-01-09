#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <cctype>
# include "contacts.hpp"

class phonebook
{
private:
	contact	cont[8];
public:
	phonebook(/* args */);
	~phonebook();
	contact *get_contacts();
};

#endif