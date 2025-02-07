#include "humanA.hpp"
#include "weapon.hpp"
#include "humanB.hpp"

int main(void)
{
	Weapon	clurb;
	clurb.set_type("clurb");

	HumanA	guy("john", clurb);

	guy.attack();

	HumanB	guyb("carl");
	guyb.attack();
	Weapon	gun;
	gun.set_type("Pistol");
	guyb.set_weapon(gun);
	guyb.attack();
}