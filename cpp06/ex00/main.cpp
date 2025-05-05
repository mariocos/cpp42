#include "ScalarConverter.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Please insert only 1 char,int,float or double\n";
		return (1);
	}
	ScalarConverter::convert(av[1]);
	return (0);
}