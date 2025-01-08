#include <iostream>
#include <cctype>
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
	default:
		break;
	}
}

phonebook::phonebook(/* args */)
{
}

phonebook::~phonebook()
{
}

contact	*phonebook::get_contacts(void)
{
	return (cont);
}

std::string	safe_getline(void)
{
	std::string	help;
	std::getline(std::cin, help);
	if (!std::cin)
	{
		std::cout << "please dont do that :(\n";
		exit (1);
	}
	return (help);
}


void	add_protocol(int index, contact *cont)
{
	std::string helper;

	std::cout << "give us their first name\n";
	cont[index].set_param(1, safe_getline());
	std::cout << "give us their last name\n";
	cont[index].set_param(2, safe_getline());
	std::cout << "give us their phone number\n";
	cont[index].set_param(3, safe_getline());
	std::cout << "give us their nickname\n";
	cont[index].set_param(4, safe_getline());
}

void	std_print(std::string str)
{
	int	len = str.length();
	int j;

	if (len < 10)
	{

		for (j = 0; j + len < 10; j++)
			std::cout << " ";
		std::cout << str << ".";
	}
	else
	{
		std::cout.write(str.c_str(), 9);
		std::cout << ".";
	}
}

void	print_contact(contact *cont, int i)
{
	std::cout << "[" << i + 1 << "] ";
	std::cout << "|";
	std_print(cont[i].get_param(1));
	std::cout << "|";
	std_print(cont[i].get_param(2));
	std::cout << "|";
	std_print(cont[i].get_param(3));
	std::cout << "|";
	std_print(cont[i].get_param(4));
	std::cout << "|\n";
}

void	print_protocol(contact *cont)
{
	std::cout << "[i] |First name.| Last name.|Phn.Number.|  Nickname.|\n";
	for (int i = 0; i < 8; i++)
	{
		print_contact(cont, i);
	}
}

void	search_protocol(contact *cont)
{
	std::string help;

	print_protocol(cont);
	std::cout << "what index are you looking for?\n> ";
	help = safe_getline();
	int	index = 0;
	index = std::atoi(help.c_str());
	if (index <= 0 || index > 8)
		std::cout << "contact not found :(\n";
	else
	{
		std::cout <<"is this what you wanted\n";
		print_contact(cont, index - 1);
	}
}

void	init_book(contact *cont)
{
	for (int i = 0; i < 8; i++)
	{
		cont[i].set_param(1, "");
		cont[i].set_param(2, "");
		cont[i].set_param(3, "");
		cont[i].set_param(4, "");
	}
}

int main(void)
{
	int	i;
	std::string str;
	contact	*cont;
	phonebook	pbook;
	std::string input;

	cont = pbook.get_contacts();
	init_book(cont);
	i = 0;
	while (1)
	{
		std::cout << "what do you want to do [ADD] [SEARCH] [EXIT]\n> ";
		input = safe_getline();
		if (input == "EXIT")
		{
			std::cout << "You are free to leave\nexit\n";
			exit(0);
		}
		else if (input == "ADD")
		{
			std::cout << "please give me the info to set a contact\n";
			add_protocol(i % 8, cont);
			i++;
		}
		else if (input == "SEARCH")
			search_protocol(cont);
		else
			std::cout << "if you want to leave just say so\n";
	}
	return (0);
}