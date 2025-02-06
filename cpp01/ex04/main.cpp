#include <iostream>
#include <fstream>
#include <string>

std::string	ft_replace(std::string line, std::string s1, std::string s2)
{
	for(int	start = line.find(s1); start != -1; start = line.find(s1))
	{
		line.erase(start, s1.length());
		line.insert(start, s2);
	}
	return (line);
}


int main(int argc, char **argv)
{
	if (argc != 4)
	{
		std::cout << "please call this with valid args\n";
		return (1);
	}
	std::string 	s1(argv[2]);
	std::string 	s2(argv[3]);
	if (!*argv[1] || s1.empty() || s2.empty())
	{
		std::cout << "please dont use empty params :p\n";
		return (1);
	}
	std::ifstream 	file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "couldnt open file:/\n";
		return (1);
	}
	std::string		suf = ".replace";
	std::string		n_file(argv[1] + suf);
	std::ofstream	new_file(n_file.c_str());
	if (!new_file.is_open())
	{
		std::cout << "problems creating new file:(\n";
		return (1);
	}
	std::string line;
	while (getline(file, line))
	{
		line = ft_replace(line, s1, s2);
		new_file << line << "\n";
	}
	return (0);
}