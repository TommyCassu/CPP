#include "./Zombie.hpp"

Zombie::Zombie()
{
    std::cout << "Zombie default constructor called." << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
    std::cout << "Zombie constructor for " << this->name << " called." << std::endl;
}

Zombie::~Zombie(void)
{
    std::cout << this->name << " is dead" << std::endl;
}

void    Zombie::announce()
{
    std::cout << Zombie::name << ": BraiiiiiiiinnnnzzzzzZ..." << std::endl;
}