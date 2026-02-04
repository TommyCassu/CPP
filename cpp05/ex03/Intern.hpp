# ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern &oldIntern);
        Intern& operator=(const Intern &oldIntern);
        ~Intern();
        AForm* makeForm(std::string request, std::string target);

        class      UnknowInputRequestException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

# endif