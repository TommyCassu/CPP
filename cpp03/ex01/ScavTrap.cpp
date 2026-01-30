#include "ScavTrap.hpp"

/* Canonical Form */
ScavTrap::ScavTrap() : ClapTrap("ScavTrap")
{
    _name= "ScavTrap";
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "Default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ScavTrap Constructor with param(s) called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &scavtrap) : ClapTrap(scavtrap)
{
    std::cout << "ScavTrap Copy constructor called" << std::endl;
    *this = scavtrap;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &scavtrap)
{
    if (this != &scavtrap)
    {
        this->_name = scavtrap._name;
        this->_attackDamage = scavtrap._attackDamage;
        this->_energyPoint = scavtrap._energyPoint;
        this->_hitPoint = scavtrap._hitPoint;
    }
    std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    return *this;
}

/* Public Functions */

void    ScavTrap::attack(const std::string& target)
{
    if (this->_hitPoint == 0)
        std::cout << "ScavTrap" << this->_name << " is already dead." << std::endl;
    else if (this->_energyPoint == 0)
        std::cout << "ScavTrap" << this->_name << " don't have enough energy to attack." << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->_name << " attack " << target << " , causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoint -= 1;
    }
}

void    ScavTrap::guardGate()
{
    if (this->_hitPoint == 0)
        std::cout << "ScavTrap" << this->_name << " is already dead." << std::endl;
    else if (this->_energyPoint == 0)
        std::cout << "ScavTrap" << this->_name << " don't have enough energy to be in Gate keeper mode." << std::endl;
    else
    {
        std::cout << "ScavTrap " << this->_name << " enter in gate keeper mode !" << std::endl;
        this->_energyPoint -= 1;
    }
}
