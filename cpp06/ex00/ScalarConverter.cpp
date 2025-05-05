#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& string)
{
	if (string.empty())
	{
		std::cout << "invalid input\n";
		return ;
	}
	int type_code = find_type(string, string.length());
	switch (type_code)
	{
	case (0):
		print_special(string);
		break;
	case (1):
		prINT(string);
		break;
	case (2):
		print_char(string);
		break;
	case (3):
		print_double(string);
		break;
	case (4):
		print_float(string);
		break;
	default:
		std::cout << "invalid input:(\n";
		break;
	}
}

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called\n";
}

ScalarConverter::ScalarConverter(ScalarConverter& cpy)
{
	std::cout << "ScalarConverter copy constructor called\n";
	*this = cpy;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter& cpy)
{
	std::cout << "ScalarConverter copy assignment operator called\n";
	(void)cpy;
	return (*this);
}