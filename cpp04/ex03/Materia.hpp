# ifndef MATERIAL_HPP
# define MATERIAL_HPP

# include <string>
# include <iostream>

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(std::string const &type);
        AMateria(const AMateria &oldMateria);
        AMateria &operator=(const AMateria &oldMateria);
        ~AMateria();
        std::string const & getType() const; //Returns the materia type
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

# endif