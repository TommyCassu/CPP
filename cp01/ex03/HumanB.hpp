# ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB();
        HumanB(std::string n);
        ~HumanB();
        void attack();
        void    setWeapon(Weapon &weapon);
    private:
        std::string name;
        Weapon *weapon;
};

# endif