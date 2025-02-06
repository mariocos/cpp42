#include <iostream>

int main(void)
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << "this is the adress of the string:" << &brain << "\n";
	std::cout << "this is the adress held by stringPTR:" << stringPTR << "\n";
	std::cout << "this the the adress held by stringREF:" << &stringREF << "\n";
	std::cout << "this is the value of the string:" << brain << "\n";
	std::cout << "this is the value of what stringPTR points to:" << *stringPTR << "\n";
	std::cout << "this is the value of what stringREF points to:" << stringREF << "\n";
}