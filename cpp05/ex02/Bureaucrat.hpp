# ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
    private:
        std::string _name;
        int         _grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &bureaucrat);
        Bureaucrat& operator=(const Bureaucrat &Bureaucrat);
        ~Bureaucrat();

        std::string getName(void) const;
        int         getGrade(void) const;
        void        setName(const std::string &name);
        void        setGrade(int grade);
        void        incrementGrade();
        void        decrementGrade();
        void        signForm(Form &form);

        class      GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class      GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &employee);
# endif