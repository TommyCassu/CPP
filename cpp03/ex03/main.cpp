#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    {
        std::cout << "\n=== Test FragTrap ===" << std::endl;
        FragTrap frag("Fraggy");
        frag.attack("target");
        frag.takeDamage(5);
        frag.beRepaired(3);
        frag.highFivesGuys();
    }

    {
        std::cout << "\n=== Test DiamondTrap ===" << std::endl;
        DiamondTrap diamond("Diamond");
        diamond.whoAmI();
        diamond.highFivesGuys();
        diamond.attack("target");
        diamond.takeDamage(99);
        diamond.beRepaired(1);
        diamond.takeDamage(100);
    }

    return (0);
}
