# include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure default constructor called" << std::endl;
};

Cure::Cure(std::string name) : AMateria("cure")
{
    std::cout << "Cure constructor with param called" << std::endl;
};

Cure::Cure(const Cure &oldCure)
{
    *this = oldCure;
    std::cout << "Cure copy constructor called" << std::endl;
};

Cure &Cure::operator=(const Cure &oldCure)
{
    if (this != &oldCure)
    {
        this->_type = oldCure.getType();
    }
    std::cout << "Cure Copy assignment operator called" << std::endl;
    return *this;
};

Cure::~Cure()
{
    std::cout << "AMataria destructor called" << std::endl;
};

AMateria* Cure::clone() const
{
    return new Cure(*this);
    std::cout << "Cure clone called" << std::endl;
};

void    Cure::use(ICharacter &target)
{
    std::cout << "* heals " << target << "'s wounds *" << std::endl;
}