#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ClapTrap Jubileus("Jubileus");
	ScavTrap Robert("Robert");
	FragTrap Jean("Jean");
	DiamondTrap Diamond("Diamond");

	Diamond.attack("Robert");
	Diamond.whoAmI();

	Jubileus.attack("Robert");
	Robert.takeDamage(0);

	Robert.attack("Jubileus");
	Jubileus.takeDamage(20);

	Jubileus.attack("Robert");

	Robert.beRepaired(7);

	Jubileus.attack("Robert");

	Jean.attack("Robert");
	Robert.guardGate();
	Robert.takeDamage(10);
	Jean.highFivesGuys();

	std::cout << "Use copy/ assignation operator" << std::endl;
	ClapTrap Jubileus2 = Jubileus;
	ScavTrap Robert2(Robert);
	FragTrap Jean2(Jean);
	DiamondTrap Diamond2 = Diamond;

	Jubileus2.attack("Robert");
	Robert2.guardGate();
	Jean2.highFivesGuys();
	Diamond2.whoAmI();

	return 0;
}