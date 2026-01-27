#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(std::string type) :_type(type)
{
    std::cout << "Animal Constructor with param(s) called" << std::endl;
}

Animal::Animal(const Animal &animal)
{
    std::cout << "Animal Copy constructor called" << std::endl;
    *this = animal;
}

Animal &Animal::operator=(const Animal &animal)
{
    this->_type = animal._type;
    std::cout << "Animal Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal Destructor called" << std::endl;
}

void    Animal::makeSound() const
{
    std::cout << "UNKNOW Sound" << std::endl;
}

std::string    Animal::getType() const
{
    return(this->_type);
}