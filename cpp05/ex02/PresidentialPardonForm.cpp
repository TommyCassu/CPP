# include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default_Presidential", false, 25, 5), _target("DefaultTarget") {
    std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target + "_Presidential", false, 25, 5) {
    std::cout << "PresidentialPardonForm param(s) constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &oldPresidentialPardonForm) : AForm(oldPresidentialPardonForm.getName(), oldPresidentialPardonForm.getSigned(), oldPresidentialPardonForm.getRequireToSign(), oldPresidentialPardonForm.getRequireToExec()) {
    std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm& oldPresidentialPardonForm) {
     std::cout << "PresidentialPardonForm Copy assignement operator called" << std::endl;
    if (this != &oldPresidentialPardonForm)
        this->_target = oldPresidentialPardonForm._target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "PresidentialPardonForm destructor called" << std::endl;
}
