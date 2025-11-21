# ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
    public:
        Harl(void);
        void    complain(std::string level);
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        struct harl_level
        {
            std::string level_name;
            void    (Harl::*func)();
        };
        harl_level level[4];
        
};

# endif