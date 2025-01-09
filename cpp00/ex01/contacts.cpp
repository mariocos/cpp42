#include "contacts.hpp"
#include "phonebook.hpp"

contact::contact()
{
}

contact::~contact()
{
}

std::string contact::get_param(int code)
{
	switch (code)
	{
	case 1:
		return (first_name);
		break;
	case 2:
		return (last_name);
		break;
	case 3:
		return (nbr);
		break;
	case 4:
		return (nick);
		break;
	case 5:
		return (secret);
		break;
	default:
		break;
	}
	return (NULL);
}
void	contact::set_param(int code, std::string value)
{
	switch (code)
	{
	case 1:
		first_name = value;
		break;
	case 2:
		last_name = value;
		break;
	case 3:
		nbr = value;
		break;
	case 4:
		nick = value;
		break;
	case 5:
		secret = value;
		break ;
	default:
		break;
	}
}