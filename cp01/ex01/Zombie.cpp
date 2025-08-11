#include "Zombie.hpp"

Zombie::Zombie() {};

void    Zombie::announce(void)
{
    std::cout << this->name << ": BRAIIOIINNZZZ" << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is dead" << std::endl;
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}