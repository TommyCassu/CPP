#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &cat) : Animal("Dog")
{
    *this = cat;
    this->brain = new Brain(*cat.brain);
    std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &cat)
{
    if (this != &cat)
    {
        Animal::operator=(cat);
        delete brain;
        brain = new Brain(*cat.brain);
        std::cout << "Cat Copy assignment operator called" << std::endl;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat Destructor called" << std::endl;
}

void	Cat::makeSound() const {
std::cout << "Miaou Miaou" << std::endl;
}

