#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Test ClapTrap ===" << std::endl;
    ClapTrap clap("ClapClap");
    ClapTrap clop("ClopClop");
    clap.attack("ClopClop");
    clop.takeDamage(5);
    clap.beRepaired(3);
    return (0);
}