# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"

class Bureaucrat
{
    private:
        const std::string _name;
        int         _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat& operator=(const Bureaucrat &Bureaucrat);
        ~Bureaucrat();

        std::string getName(void) const;
        int         getGrade(void) const;
        void        setGrade(int grade);
        void        incrementGrade();
        void        decrementGrade();
        void        signForm(AForm &form);

        class      GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class      GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        void    executeForm(AForm const & aform) const;
};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &employee);
# endif