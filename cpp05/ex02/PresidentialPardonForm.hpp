# ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm {
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &oldPresidentialPardonForm);
        ~PresidentialPardonForm();
        PresidentialPardonForm& operator=(const PresidentialPardonForm &oldAForm);

        void    execute(Bureaucrat const & executor) const;

};

# endif