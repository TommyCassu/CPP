# include "Harl.hpp"

Harl::Harl(void)
{
    this->level[0].level_name = "DEBUG";
    this->level[0].func = &Harl::debug;
    this->level[1].level_name = "INFO";
    this->level[1].func = &Harl::info;
    this->level[2].level_name = "WARNING";
    this->level[2].func = &Harl::warning;
    this->level[3].level_name = "ERROR";
    this->level[3].func = &Harl::error;
};

void    Harl::debug(void)
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn t put enough bacon in my burger! If you did, I wouldn t be asking for more!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << "I think I deserve to have some extra bacon for free. I ve been coming for years, whereas you started working here just last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level_name)
{
    for (int i = 0; i < 4; i++)
    {
        if (level_name == this->level[i].level_name)
        {
            (this->*level[i].func)();
            return ;
        }
    }
}

