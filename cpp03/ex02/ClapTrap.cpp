#include "ClapTrap.hpp"

/* Canonical Form */
ClapTrap::ClapTrap()
{
    _name= "ClapTrap";
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
    _name = name;
    _hitPoint = 100;
    _energyPoint = 50;
    _attackDamage = 20;
    std::cout << "ClapTrap Constructor with param(s) called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &claptrap)
{
    std::cout << "ClapTrap Copy constructor called" << std::endl;
    *this = claptrap;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &claptrap)
{
    this->_name = claptrap._name;
    this->_attackDamage = claptrap._attackDamage;
    this->_energyPoint = claptrap._energyPoint;
    this->_hitPoint = claptrap._hitPoint;
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return *this;
}

/* Public Functions */

void    ClapTrap::attack(const std::string& target)
{
    if (this->_hitPoint < 0)
        std::cout << "ClapTrap" << this->_name << " is already dead." << std::endl;
    else if (this->_energyPoint == 0)
        std::cout << "ClapTrap" << this->_name << " don't have enough energy to attack." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage" << std::endl;
        this->_energyPoint -= 1;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    if (this->_hitPoint == 0)
        std::cout << "ClapTrap " << this->_name << " can't take damage because he is already dead." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " take " << amount << " points of damage(s)" << std::endl;
        this->_hitPoint -= amount;
        if (this->_hitPoint <= 0)
        {
            this->_hitPoint = 0;
            std::cout << "ClapTrap " << this->_name << " is dead."<< std::endl;
        }
    }
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_hitPoint == 0)
        std::cout << "ClapTrap " << this->_name << " try to repair but he is already dead." << std::endl;
    else if (this->_energyPoint == 0)
        std::cout << "ClapTrap " << this->_name << " don't have enough energy to repair." << std::endl;
    else
    {
        std::cout << "ClapTrap " << this->_name << " regained " << amount << " life points." << std::endl;
        this->_energyPoint -= 1;
        this->_hitPoint += amount;
    }
}