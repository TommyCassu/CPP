#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &Brain)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    *this = Brain;
}

Brain &Brain::operator=(const Brain &brain)
{
    if (this != &brain)
    {
        for (int i = 0; i < 100; i++)
        {
            this->_ideas[i] = brain._ideas[i];
        }
    }
    std::cout << "Brain Copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor called" << std::endl;
}