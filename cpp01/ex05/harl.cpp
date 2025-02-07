#include "harl.hpp"


harl::harl(/* args */)
{
}

harl::~harl()
{
}

void	harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month.\n";
}

void	harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void	harl::complain(std::string level)
{
	std::string	levels[] = {"debug", "info", "warning", "error"};
	void	(harl::*_complainPtr[])(void) = {&harl::debug, &harl::info, &harl::warning, &harl::error};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*_complainPtr[i])();
			return ;
		}
	}
	std::cout << "level not set cant complain about everything\n";
}
