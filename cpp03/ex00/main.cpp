#include "ClapTrap.hpp"

int main()
{
    ClapTrap a("Toto");
    ClapTrap b("Titi");
    a.attack("Titi");
    b.takeDamage(5);
    b.beRepaired(5);
    a.attack("Titi");
    b.takeDamage(10);
    b.beRepaired(5);
    a.attack("Titi");
    b.takeDamage(10);

    return (0);
}