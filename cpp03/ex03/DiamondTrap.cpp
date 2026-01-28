#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

/* Canonical Form */
DiamondTrap::DiamondTrap() : ClapTrap("DiamondTrap"), ScavTrap("DiamondTrap"), FragTrap("DiamondTrap")
{
    _name = "DiamondTrap";
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << "Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name)
{
    _name = name;
    _hitPoint = FragTrap::_hitPoint;
    _energyPoint = ScavTrap::_energyPoint;
    _attackDamage = FragTrap::_attackDamage;
    std::cout << ClapTrap::_name << std::endl;

    std::cout << "DiamondTrap Constructor with param(s) called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondtrap) : ClapTrap(diamondtrap), ScavTrap(diamondtrap), FragTrap(diamondtrap)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    this->_name = diamondtrap._name;
    this->ClapTrap::_name = diamondtrap.ClapTrap::_name;
    this->_attackDamage = diamondtrap._attackDamage;
    this->_energyPoint = diamondtrap._energyPoint;
    this->_hitPoint = diamondtrap._hitPoint;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondtrap)
{
    this->_name = diamondtrap._name;
    this->ClapTrap::_name = diamondtrap.ClapTrap::_name;
    this->_attackDamage = diamondtrap._attackDamage;
    this->_energyPoint = diamondtrap._energyPoint;
    this->_hitPoint = diamondtrap._hitPoint;
    std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    return *this;
}

/* Public Functions */

void    DiamondTrap::whoAmI()
{
    std::cout << "My DiamondTrap name is : " << this->_name << " and my ClapTrap name is : " << ClapTrap::_name << std::endl;
}