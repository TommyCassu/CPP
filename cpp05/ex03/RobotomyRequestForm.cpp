# include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", false, 72, 45), _target("DefaultTarget") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyForm", false, 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm param(s) constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &oldRobotomyRequestForm) : AForm(oldRobotomyRequestForm.getName(), oldRobotomyRequestForm.getSigned(), oldRobotomyRequestForm.getRequireToSign(), oldRobotomyRequestForm.getRequireToExec()) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm& oldRobotomyRequestForm) {
     std::cout << "RobotomyRequestForm Copy assignement operator called" << std::endl;
    if (this != &oldRobotomyRequestForm)
        this->_target = oldRobotomyRequestForm._target;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

void    RobotomyRequestForm::executeThisForm() const {
    std::srand(std::time(NULL));
    std::cout << "\'\'\'BRBRBRBRBR\'\'\'. ";
    if (std::rand() % 2)
        std::cout << this->_target << " have been robotized !" << std::endl;
    else
        std::cout << this->_target << " robotomy failed !" << std::endl;
}