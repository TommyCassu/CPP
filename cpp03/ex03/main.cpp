#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	DiamondTrap one("Mage");
	DiamondTrap two("Est");
	DiamondTrap three("Lent");
	
	one.whoAmI();
	two.whoAmI();
	three.whoAmI();
	DiamondTrap four(one);
	four.whoAmI();
	four.attack("BullShark");
	four.guardGate();
	four.highFivesGuys();
	return (0);
}