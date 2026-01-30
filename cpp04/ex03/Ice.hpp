# ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include <iostream>

# include "Materia.hpp"

class Ice : public AMateria
{
    public:
        Ice();
        Ice(std::string name);
        Ice(const Ice &oldIce);
        Ice &operator=(const Ice &oldIce);
        ~Ice();

        AMateria* clone() const;
        void use(ICharacter& target);

};

# endif