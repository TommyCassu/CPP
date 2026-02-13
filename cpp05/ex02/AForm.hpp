# ifndef AAFORM_HPP
# define AAFORM_HPP

# include <iostream>

class Bureaucrat;

class AForm {
    private:
        const std::string   _name;
        bool                _isSigned;
        const int _requiredGradeToSign;
        const int _requiredGradeToExec;
    public:
        AForm();
        AForm(const std::string name, bool isSigned, const int requiredGradeToSign, const int requiredGradeToExec);
        AForm(const AForm &oldAForm);
        virtual ~AForm();
        AForm& operator=(const AForm &oldAForm);

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
        class      FormIsNotSignedException : public std::exception{
            public:
                virtual const char* what() const throw();
        };

        virtual void    execute(Bureaucrat const & executor) const = 0;
};

std::ostream    &operator<<(std::ostream &os, const AForm &Aform);

# endif