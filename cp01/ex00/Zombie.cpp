#include "./Zombie.hpp"

Zombie::Zombie(std::string name)
{
    this->name = name;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is dead" << std::endl;
}

void    Zombie::announce()
{
    std::cout << Zombie::name << ": BraiiiiiiiinnnnzzzzzZ..." << std::endl;
}