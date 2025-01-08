#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (1);
	}
	int	i = -1;
	int	j = 0;
	while (argv[++j])
	{
		i = -1;
		while (argv[j][++i])
		{
			if (std::islower(argv[j][i]))
				argv[j][i] -= 32;
			std::cout << argv[j][i];
		}
		std::cout << " ";
	}
	std::cout << std::endl;
	return (0);
}