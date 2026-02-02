# ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <cstdlib>
# include <ctime>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm {
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(const RobotomyRequestForm &oldRobotomyRequestForm);
        ~RobotomyRequestForm();
        RobotomyRequestForm& operator=(const RobotomyRequestForm &oldForm);
        void    executeThisForm() const ;


};

# endif