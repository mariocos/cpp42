#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base* generate(void)
{
	int	i = rand() % 3;

	switch (i)
	{
	case 0:
		return (new A);
		break;
	case 1:
		return (new B);
		break;
	default:
		return (new C);
		break;
	}
}

void	identify(Base* p)
{
	A* a = dynamic_cast<A*>(p);
	if (a)
		std::cout << "I identify this as a A class\n";
	B* b = dynamic_cast<B*>(p);
	if (b)
		std::cout << "I identify this as a B class\n";
	C* c = dynamic_cast<C*>(p);	
	if (c)
		std::cout << "I identify this as a C class\n";
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "I identify this as a A class\n";
		(void)a;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "I identify this as a B class\n";
		(void)b;
	}
	catch(const std::exception& e)
	{
	}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "I identify this as a C class\n";
		(void)c;
	}
	catch(const std::exception& e)
	{
	}
}



int main(void)
{
	srand(time(NULL));
	for (int i = 0; i < 10; i++)
	{
		Base	*ptr = generate();
		Base	&ref = *ptr;
		std::cout << "Executing identify ptr: ";
		identify(ptr);
		std::cout << "Executing identify ref: ";
		identify(ref);
		delete ptr;
	}
}