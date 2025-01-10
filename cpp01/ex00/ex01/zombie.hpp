#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
private:
	/* data */
	std::string	name;
public:
	std::string	get_param(int code);
	void	set_param(int code, std::string);
	void	announce(void);
	Zombie(/* args */);
	~Zombie();
};



#endif