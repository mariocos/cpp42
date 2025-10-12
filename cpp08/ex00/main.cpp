#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	
	std::cout << "std::vector [1, 2, 3, 4, 5]" << std::endl;
	
	try
	{
		std::cout << "trying to find 3 in vector\n";
		std::vector<int>::iterator it = easyfind(vec, 3);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "trying to find 42 in vector\n";
		easyfind(vec, 42);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	
	std::cout << "\nstd::list [10, 20, 30]" << std::endl;
	
	try
	{
		std::cout << "tring to find 20 in list\n";
		std::list<int>::iterator it = easyfind(lst, 20);
		std::cout << "Found: " << *it << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	try
	{
		std::cout << "trying to find 99 in list\n";
		easyfind(lst, 99);
	}
	catch (const std::exception& e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}

