# include "HumanB.hpp"

HumanB::HumanB() : weapon(NULL)
{
    std::cout << "HumanB default constructor called." << std::endl;
};

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
    std::cout << "HumanB constructor with param called." << std::endl;
};

HumanB::~HumanB()
{
    std::cout << "HumanB destructor called." << std::endl;
};

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack(void)
{
    if (this->weapon)
    {
        std::cout   << this->name
                    << " attacks with their "
                    << this->weapon->getType()
                    << std::endl;
    }
    else
    {
        std::cout   << this->name
                    << " attacks with nothing"
                    << std::endl;
    }
    
};