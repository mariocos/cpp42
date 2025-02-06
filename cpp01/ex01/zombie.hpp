#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP
# include <iostream>


class Zombie
{
public:
	std::string	get_param(int code);
	void	set_param(int code, std::string);
	void	announce(void);
	Zombie(/* args */);
	~Zombie();
private:
	std::string	name;
};
#endif