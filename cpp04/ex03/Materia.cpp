#include "Materia.hpp"

AMateria::AMateria() : _type("DefaultType")
{
    std::cout << "AMataria default constructor called" << std::endl;
};

AMateria::AMateria(std::string const &type) : _type(type)
{
    std::cout << "AMataria constructor with param called" << std::endl;
};

AMateria::AMateria(const AMateria &oldMateria)
{
    *this = oldMateria;
    std::cout << "AMataria copy constructor called" << std::endl;
};

AMateria &AMateria::operator=(const AMateria &oldMateria)
{
    if (this != &oldMateria)
    {
        this->_type = oldMateria.getType();
    }
    std::cout << "AMataria Copy assignment operator called" << std::endl;
    return *this;
};

AMateria::~AMateria()
{
    std::cout << "AMataria destructor called" << std::endl;
};

std::string const & AMateria::getType() const 
{
    return this->_type;
}

void    AMateria::use(ICharacter &target) {};
