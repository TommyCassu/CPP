# include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    this->setName("defaultName");
    this->setGrade(1);
    std::cout << "Bureaucrat Default constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(std::string name, int grade) {
    this->setName(name);
    this->setGrade(grade);
    std::cout << "Bureaucrat param(s) constructor called" << std::endl;
};

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : _name(bureaucrat._name), _grade(bureaucrat._grade) {
    std::cout << "Bureaucrat Copy constructor called" << std::endl;
};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat) {
    std::cout << "Bureaucrate Copy assignement operator constructor called" << std::endl;
    if (this != &bureaucrat)
        _grade = bureaucrat._grade;
    return *this;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "Bureaucrate Destructor called" << std::endl;
};

std::string Bureaucrat::getName(void) const {
    return this->_name;
}

int Bureaucrat::getGrade(void) const {
    return this->_grade;
}

void Bureaucrat::setName(const std::string &name){
    this->_name = name;
}

void Bureaucrat::setGrade(int grade){
    if (grade > 150)
        throw GradeTooLowException();
    else if (grade < 1)
        throw GradeTooHighException();
    else
        this->_grade = grade;
}

void    Bureaucrat::incrementGrade(void) {
    this->setGrade(this->_grade - 1);
}

void    Bureaucrat::decrementGrade(void) {
    this->setGrade(this->_grade + 1);
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return ("Grade value out of range ! (1-150)");
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return ("Grade value out of range ! (1-150)");
}

std::ostream    &operator<<(std::ostream &os, const Bureaucrat &employee)
{
    os << employee.getName() << ", bureaucrat grade " << employee.getGrade() << ".";
    return (os);
}