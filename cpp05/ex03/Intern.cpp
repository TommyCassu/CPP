#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern::Intern(const Intern &oldIntern) {
    *this = oldIntern;
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &oldIntern) {
    (void)oldIntern;
    std::cout << "Intern Copy assignement operator called" << std::endl;
    return *this;
}

AForm* createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string request, std::string target) {
    static std::string FormName[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    static AForm* (*FormListCreators[3])(const std::string&) = {
        createShrubberyCreationForm,
        createRobotomyRequestForm,
        createPresidentialPardonForm
    };
    for (int i = 0; i < 3; i++) {
        if (request == FormName[i]) {
            std::cout << "Intern creates" << request << std::endl;
            return FormListCreators[i](target);
        }
    }
    std::cout << "Error. Provided form name \""<< request << "\" does not exist ! " << std::endl;
    return NULL;
}