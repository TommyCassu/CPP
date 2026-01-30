# ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include <iostream>

# include "Materia.hpp"

class Cure : public AMateria
{
    public:
        Cure();
        Cure(std::string name);
        Cure(const Cure &oldCure);
        Cure &operator=(const Cure &oldCure);
        ~Cure();

        AMateria* clone() const;
        void use(ICharacter& target);

};

# endif