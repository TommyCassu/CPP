#include "FragTrap.hpp"

/* Canonical Form */
FragTrap::FragTrap() : ClapTrap("FragTrap")
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 100;
    _attackDamage = 30;
    std::cout << "FragTrap Constructor with param(s) called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &fragtrap) : ClapTrap(fragtrap)
{
    std::cout << "FragTrap Copy constructor called" << std::endl;
    *this = fragtrap;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &fragtrap)
{
    if (this != &fragtrap)
    {
        this->_name = fragtrap._name;
        this->_attackDamage = fragtrap._attackDamage;
        this->_energyPoint = fragtrap._energyPoint;
        this->_hitPoint = fragtrap._hitPoint;
    }
    std::cout << "FragTrap Copy assignment operator called" << std::endl;
    return *this;
}

/* Public Functions */

void    FragTrap::attack(const std::string& target)
{
    if (this->_hitPoint == 0)
        std::cout << "FragTrap" << this->_name << " is already dead." << std::endl;
    else if (this->_energyPoint == 0)
        std::cout << "FragTrap" << this->_name << " don't have enough energy to attack." << std::endl;
    else
    {
        std::cout << "FragTrap " << this->_name << " attack " << target << " , causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoint -= 1;
    }
}

void    FragTrap::highFivesGuys()
{
    if (this->_hitPoint == 0)
        std::cout << "FragTrap" << this->_name << " is already dead." << std::endl;
    else if (this->_energyPoint == 0)
        std::cout << "FragTrap" << this->_name << " don't have enough energy to start a High Five." << std::endl;
    else
    {
        std::cout << " Hey ! " << this->_name << " gives a High Five !" << std::endl;
        this->_energyPoint -= 1;
    }
}
