#include "Bureucrat.hpp"

int main(void)
{
	Bureucrat a;
	std::cout << a;

	for (int i = 0 ; i < 51 ; i++)
	{
		try
		{
			std::cout << "attempting to decrement grade\n";
			a.DecrementGrade();
		}
		catch (const std::exception& ex)
		{
			std::cerr << ex.what();
		}
	}
}