#include "ScavTrap.hpp"

int main(void)
{
	{
        std::cout << "=== Test ClapTrap ===" << std::endl;
        ClapTrap clap("ClapClap");
        ClapTrap clop("ClopClop");
        clap.attack("ClopClop");
        clop.takeDamage(5);
        clap.beRepaired(3);
    }
    {
        std::cout << "\n=== Test ScavTrap ===" << std::endl;
        ScavTrap scav("Scavax");
        scav.attack("target");
        scav.takeDamage(5);
        scav.beRepaired(3);
        scav.guardGate();
    }


	return 0;
}