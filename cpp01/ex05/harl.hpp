#ifndef HARL_HPP
#define HARL_HPP

class harl
{
private:
	/* data */
	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
public:
	harl(/* args */);
	~harl();
	void	complain(std::string level);
};

harl::harl(/* args */)
{
}

harl::~harl()
{
}

void	harl::complain(std::string level)






#endif