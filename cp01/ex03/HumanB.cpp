# include "HumanB.hpp"

HumanB::HumanB(std::string name, Weapon &weapon) : name(name), weapon(weapon) {} ;

void    HumanB::attack(void)
{
    std::cout   << this->name
                << " attacks with their "
                << this->weapon.getType()
                << std::endl;
};