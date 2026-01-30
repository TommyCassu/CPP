#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &Wrongcat) : WrongAnimal("Dog")
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
    *this = Wrongcat;
}

WrongCat &WrongCat::operator=(const WrongCat &wrongcat)
{
    this->_type = wrongcat._type;
    std::cout << "WrongCat Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat Destructor called" << std::endl;
}

void    WrongCat::makeSound() const
{
    std::cout << "Miiaaaaaaaouxxxxx" << std::endl;
}

