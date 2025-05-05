#include "ScalarConverter.hpp"

void	print_special(const std::string& string)
{
	if (string == "nanf" || string == "nan")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else if (string == "+inf" || string == "+inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: +inff\n";
		std::cout << "double: +inf\n";
	}
	else if (string == "-inf" || string == "-inff")
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: -inff\n";
		std::cout << "double: -inf\n";
	}
}

void	prINT(const std::string& string)
{
	long	nb = atol(string.c_str());

	if (nb > 127 || nb < 0)
		std::cout << "char: impossible\n";
	else if (!isprint(nb))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: " << "'" << static_cast<char>(nb) << "'\n";
	if (nb >> sizeof(int) != 0)//checks if its out of int range
		std::cout << "int: impossible\n";
	else
		std::cout << "int: " << static_cast<int>(nb) << "\n";
	std::cout << "float: " << static_cast<int>(nb) << ".0f\n";
	std::cout << "double: " << static_cast<int>(nb) << ".0\n";

}

void	print_char(const std::string& string)
{
	char	c;

	if (!string[1])
		c = string[0];
	else
		c = string[1];
	if (isprint(c))
		std::cout << "char: " << c << "\n";
	else
		std::cout << "char: Not displayable\n";
	std::cout<<"int: " << static_cast<int>(c) << "\n";
	std::cout<<"float: " << static_cast<float>(c) << ".0f\n";
	std::cout<<"double: " << static_cast<double>(c) << ".0\n";
}

void	print_double(const std::string& string)
{
	double	nb = atof(string.c_str());
	bool	has_decimal = (fabs(nb - static_cast<int>(nb)) < 0.0000000000001);

	/* char */
	if (nb < 0 || nb > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(nb))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nb) << "\n";

	/* int */
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else 
		std::cout << "int: " << static_cast<int>(nb) << "\n";

	/* float */
	if (nb < std::numeric_limits<float>::min() || nb > std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else if (!has_decimal)
		std::cout << "float: " << static_cast<float>(nb) << "f\n";
	else
		std::cout << "float: " << static_cast<float>(nb) << ".0f\n";

	/* double */
	if (nb < std::numeric_limits<double>::min() || nb > std::numeric_limits<double>::max())
		std::cout << "double: impossible\n";
	else if (!has_decimal)
		std::cout << "double: " << static_cast<double>(nb) << "\n";
	else
		std::cout << "double: " << static_cast<double>(nb) << ".0\n";
}


void	print_float(const std::string& string)
{
	float	nb = atof(string.c_str());
	bool	has_decimal = (fabs(nb - static_cast<int>(nb)) < 0.0000000000001);

	/* char */
	if (nb < 0 || nb > 127)
		std::cout << "char: impossible\n";
	else if (!isprint(nb))
		std::cout << "char: Not displayable\n";
	else
		std::cout << "char: " << static_cast<char>(nb) << "\n";

	/* int */
	if (nb < std::numeric_limits<int>::min() || nb > std::numeric_limits<int>::max())
		std::cout << "int: impossible\n";
	else 
		std::cout << "int: " << static_cast<int>(nb) << "\n";

	/* float */
	if (nb < std::numeric_limits<float>::min() || nb > std::numeric_limits<float>::max())
		std::cout << "float: impossible\n";
	else if (!has_decimal)
		std::cout << "float: " << static_cast<float>(nb) << "f\n";
	else
		std::cout << "float: " << static_cast<float>(nb) << ".0f\n";

	/* double */
	if (!has_decimal)
		std::cout << "double: " << static_cast<double>(nb) << "\n";
	else
		std::cout << "double: " << static_cast<double>(nb) << ".0\n";
}
