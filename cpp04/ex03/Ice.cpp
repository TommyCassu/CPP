# include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice default constructor called" << std::endl;
};

Ice::Ice(std::string name) : AMateria("ice")
{
    std::cout << "Ice constructor with param called" << std::endl;
};

Ice::Ice(const Ice &oldIce)
{
    *this = oldIce;
    std::cout << "Ice copy constructor called" << std::endl;
};

Ice &Ice::operator=(const Ice &oldIce)
{
    if (this != &oldIce)
    {
        this->_type = oldIce.getType();
    }
    std::cout << "Ice Copy assignment operator called" << std::endl;
    return *this;
};

Ice::~Ice()
{
    std::cout << "AMataria destructor called" << std::endl;
};

AMateria* Ice::clone() const
{
    return new Ice(*this);
    std::cout << "Ice clone called" << std::endl;
};

void    Ice::use(ICharacter &target)
{
    std::cout << "* shoots an ice bolt at " << target << " *" << std::endl;
}