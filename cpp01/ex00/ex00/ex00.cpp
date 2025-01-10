#include <iostream>

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

Zombie::Zombie(/* args */)
{
}

Zombie::~Zombie()
{
	std::cout << name << " is tired of living\n";
}

void	Zombie::announce(void)
{
	std::cout << get_param(1) << " : BraiiiiiiinnnzzzZ...\n";
}

std::string	Zombie::get_param(int code)
{
	switch (code)
	{
	case 1:
		return (name);
		break;
	default:
		break;
	}
	return ("");
}


void	Zombie::set_param(int code, std::string value)
{
	switch (code)
	{
	case 1:
		name = value;
		break;
	
	default:
		break;
	}
}

Zombie	*newZombie(std::string name)
{
	Zombie	*zombo = new(Zombie);


	if (name.empty())
		zombo->set_param(1, "carl");
	else
		zombo->set_param(1, name);
	return (zombo);
}

void randomChump(std::string name)
{
	Zombie zombo;

	if (name.empty())
		zombo.set_param(1, "joe");
	else
		zombo.set_param(1, name);
	zombo.announce();
}

int main(void)
{
	randomChump("vasco");
	Zombie	*zombo = newZombie("gnut");
	zombo->announce();
	delete(zombo);
}