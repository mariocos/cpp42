#pragma once
#include <iostream>
# include <cmath>
# include <limits>

class ScalarConverter
{
public:
	ScalarConverter();
	ScalarConverter(ScalarConverter& cpy);
	ScalarConverter& operator=(ScalarConverter& cpy);
	virtual ~ScalarConverter() = 0;
	static void	convert(const std::string& string);
};

void	print_special(const std::string& string);
void	prINT(const std::string& string);
void	print_char(const std::string& string);
void	print_double(const std::string& string);
void	print_float(const std::string& string);
int	check_if_int(const std::string& string, size_t len);
int	check_if_float(const std::string& string, size_t len, size_t dot_pos);
int	find_type(const std::string &string, size_t len);
