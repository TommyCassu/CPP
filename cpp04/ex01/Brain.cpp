#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &brain)
{
    std::cout << "Brain Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
    {
        this->_ideas[i] = brain._ideas[i];
    }
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

std::string Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
    {
        std::cout << "Error ! Please enter an index between 0 and 100" << std::endl;
        return "";
    }
    return _ideas[index];
}

void    Brain::setIdea(int index, std::string idea)
{
    if (index < 0 || index >= 100)
    {
        std::cout << "Error ! Please enter an index between 0 and 100" << std::endl;
        return ;
    }
    _ideas[index] = idea;
}