# ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int _requiredGradeToSign;
        const int _requiredGradeToExec;
    public:
        Form();
        Form(const std::string name, bool isSigned, const int requiredGradeToSign, const int requiredGradeToExec);
        Form(const Form &oldForm);
        ~Form();
        Form& operator=(const Form &oldForm);
        
        std::string getName() const;
        bool        getSigned() const;
        int         getRequireToSign() const;
        int         getRequireToExec() const;
        void        beSigned(Bureaucrat &bureaucrat);

        class      GradeTooHighException : public std::exception{
            public:
                virtual const char* what() const throw();
        };
        class      GradeTooLowException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

};

std::ostream    &operator<<(std::ostream &os, const Form &form);

# endif