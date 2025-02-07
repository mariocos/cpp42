#include "humanA.hpp"
#include "weapon.hpp"

int main(void)
{
	Weapon	clurb;
	clurb.set_type("clurb");

	HumanA	guy("john", clurb);

	guy.attack();

}