#include "Weapon.hpp"

Weapon::Weapon()
{
    std::cout << "Weapon default constructor called." << std::endl;
};
Weapon::Weapon(std::string type) : type(type)
{
    std::cout << "Weapon constructor with param called." << std::endl;
};

Weapon::~Weapon()
{
    std::cout << "Weapon destructor called." << std::endl;
};

const std::string &Weapon::getType(void) const 
{
    return (this->type);
};

void    Weapon::setType(std::string type)
{
    this->type = type;
}