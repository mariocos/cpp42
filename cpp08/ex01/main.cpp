#include "Span.hpp"
#include <iostream>
#include <vector>

int main()
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
	
	Span sp2 = Span(10000);
	
	for (int i = 0; i < 10000; ++i)
		sp2.addNumber(i);
	
	std::cout << "shortestSpan: " << sp2.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp2.longestSpan() << std::endl;
	
	std::vector<int> vec;
	for (int i = 0; i < 100; ++i)
		vec.push_back(i * 10);
	
	Span sp3 = Span(100);
	sp3.addRange(vec.begin(), vec.end());
	
	std::cout << "shortestSpan: " << sp3.shortestSpan() << std::endl;
	std::cout << "longestSpan: " << sp3.longestSpan() << std::endl;
	
	try
	{
		Span sp4 = Span(2);
		sp4.addNumber(1);
		sp4.addNumber(2);
		sp4.addNumber(3);
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Span sp5 = Span(1);
		sp5.addNumber(42);
		sp5.shortestSpan();
	}
	catch (const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}

