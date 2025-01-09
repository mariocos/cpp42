#include <iostream>
#include <cctype>
#include <cstdlib>
#include "contacts.hpp"
#include "phonebook.hpp"

int	add_protocol(int index, contact *cont)
{
	std::string new_fname;
	std::string new_lname;
	std::string new_nbr;
	std::string new_nick;
	std::string new_secret;

	std::cout << "give us their first name\n> ";
	std::getline(std::cin, new_fname);
	if (!std::cin)
		return (-1);
	if (new_fname == "")
		return (-2);
	std::cout << "give us their last name\n> ";
	std::getline(std::cin, new_lname);
	if (!std::cin)
		return (-1);
	if (new_lname == "")
		return (-2);
	std::cout << "give us their phone number\n> ";
	std::getline(std::cin, new_nbr);
	if (!std::cin)
		return (-1);
	if (new_nbr == "")
		return (-2);
	std::cout << "give us their nickname\n> ";
	std::getline(std::cin, new_nick);
	if (!std::cin)
		return (-1);
	if (new_nick == "")
		return (-2);
	std::cout << "give us their secret\n> ";
	std::getline(std::cin, new_secret);
	if (!std::cin)
		return (-1);
	if (new_secret == "")
		return (-2);
	cont[index].set_param(1, new_fname);
	cont[index].set_param(2, new_lname);
	cont[index].set_param(3, new_nbr);
	cont[index].set_param(4, new_nick);
	cont[index].set_param(5, new_secret);
	return (1);
}

void	std_print(std::string str)
{
	int	len = str.length();
	int j;

	if (len < 10)
	{
		for (j = 0; j + len <= 10; j++)
			std::cout << " ";
		std::cout << str;
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
	std_print(cont[i].get_param(4));
	std::cout << "|\n";
}

void	print_protocol(contact *cont)
{
	std::cout << "[i] |First name.| Last name.|  Nickname.|\n";
	for (int i = 0; i < 8; i++)
	{
		print_contact(cont, i);
	}
}

void	selected_contact_print(contact *cont, int i)
{
	if (cont[i].get_param(1) == "")
	{
		std::cout << "this contact hasnt been set :(\n";
		return ;
	}
	std::cout << "this is the contact info you requested\n";
	std::cout << "Name >" << cont[i].get_param(1) << "\n";
	std::cout << "Last name >" << cont[i].get_param(2) << "\n";
	std::cout << "Phone number >" << cont[i].get_param(3) << "\n";
	std::cout << "Nickname >" << cont[i].get_param(4) << "\n";
	std::cout << "Secret >" << cont[i].get_param(5) << "\n";
}

int	search_protocol(contact *cont)
{
	std::string help;

	print_protocol(cont);
	std::cout << "what index are you looking for?\n> ";
	std::getline(std::cin, help);
	if (!std::cin)
		return (-1);
	int	index = 0;
	index = std::atoi(help.c_str());
	if (index <= 0 || index > 8)
		std::cout << "contact not found :(\n";
	else
		selected_contact_print(cont, index - 1);
	return (1);
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
	int	flag;
	flag = 0;

	cont = pbook.get_contacts();
	init_book(cont);
	i = 0;
	while (1)
	{
		std::cout << "what do you want to do [ADD] [SEARCH] [EXIT]\n> ";
		std::getline(std::cin, input);
		if (!std::cin)
			return (1);
		if (input == "EXIT")
		{
			std::cout << "You are free to leave\nexit\n";
			return (0);
		}
		else if (input == "ADD")
		{
			std::cout << "please give me the info to set a contact\n";
			flag = add_protocol(i % 8, cont);
			if (flag == -1)
				return (1);
			else if (flag == -2)
				std::cout << "empty fields not allowed contact not saved\n";
			else if (flag == 1)
				i++;
		}
		else if (input == "SEARCH")
		{
			if (search_protocol(cont) < 0)
				return (1);

		}
		else
			std::cout << "if you want to leave just say so\n";
	}
	return (0);
}