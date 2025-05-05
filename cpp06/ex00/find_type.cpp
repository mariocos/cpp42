#include "ScalarConverter.hpp"

int	check_if_int(const std::string& string, size_t len)
{
	size_t	i = 0;
	bool	has_signal = false;

	if (string[0] == '+' || string[0] == '-')
	{
		i++;
		has_signal = true;
	}
	while (i < len)
	{
		if (!isdigit(string[0]))
			break ;
		i++;
	}
	if (i == len && ((has_signal == true && len < 11) || (has_signal == false && len < 10)))
		return (true);
	return (0);
}

int	check_if_float(const std::string& string, size_t len, size_t dot_pos)
{
	size_t	i = 0;

	if (string[0] == '+' || string[0] == '-')
		i++;
	while (i < dot_pos)
	{
		if (!isdigit(string[0]))
			break ;
		i++;
	}
	if (i != dot_pos)
		return (0);
	i++;
	while (i < len)
	{
		if (!isdigit(string[0]))
			break ;
		i++;
	}
	if (string[i] == 'f' && !string[i + 1])
		return (1);
	return (0);
	
}

int	find_type(const std::string &string, size_t len)
{
	size_t	f_pos = string.find("f");
	size_t	dot_pos = string.find(".");

	if (len == 0)
		return (-1);
	if (dot_pos == std::string::npos)
	{
		if (string == "-inff" || string == "+inff"
			|| string == "-inf" || string == "+inf" || string == "nan" || string == "nanf")
			return (0);
		if (check_if_int(string, len))
			return (1);
		if ((len == 1 && !isdigit(string[0])) || (len == 3 && string[0] == '\'' && string[2] == '\''))
			return (2);
		return (-1);
	}
	if (dot_pos != std::string::npos && f_pos == std::string::npos)
		return (3);
	if (dot_pos != std::string::npos && f_pos != std::string::npos)
	{
		if (check_if_float(string, len, dot_pos))
			return (4);
	}
	return (-1);
}
