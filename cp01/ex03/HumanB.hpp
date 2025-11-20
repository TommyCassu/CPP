# ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB
{
    public:
        HumanB(std::string n, Weapon &w);
        void attack();
    private:
        std::string name;
        Weapon &weapon;
};

# endif