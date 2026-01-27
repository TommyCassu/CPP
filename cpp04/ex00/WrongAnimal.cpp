#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) :_type(type)
{
    std::cout << "WrongAnimal Constructor with param(s) called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &wronganimal)
{
    std::cout << "WrongAnimal Copy constructor called" << std::endl;
    *this = wronganimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &wronganimal)
{
    this->_type = wronganimal._type;
    std::cout << "WrongAnimal Copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor called" << std::endl;
}

void    WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal UNKNOW Sound" << std::endl;
}

std::string    WrongAnimal::getType() const
{
    return(this->_type);
}