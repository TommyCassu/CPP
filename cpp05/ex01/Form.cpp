# include "Form.hpp"
# include "Bureaucrat.hpp"

Form::Form() : _name("DefaultFormName"), _isSigned(0), _requiredGradeToSign(150), _requiredGradeToExec(150) {
    std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int requiredGradeToSign, const int requiredGradeToExec) : _name(name), _isSigned(isSigned), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExec(requiredGradeToExec) {
    std::cout << "Form param(s) constructor called" << std::endl;
    if (requiredGradeToSign < 1 || requiredGradeToExec < 1)
        throw GradeTooHighException();
    else if (requiredGradeToSign > 150 || requiredGradeToExec > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &oldForm) : _name(oldForm._name), _isSigned(oldForm._isSigned), _requiredGradeToSign(oldForm._requiredGradeToSign), _requiredGradeToExec(oldForm._requiredGradeToExec) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form() {
    std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
    return _name;
}

bool    Form::getSigned() const {
    return _isSigned;
}

int     Form::getRequireToSign() const {
    return _requiredGradeToSign;
}

int     Form::getRequireToExec() const {
    return _requiredGradeToExec;
}

void    Form::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _requiredGradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw(){
    return ("Grade value out of range ! (1-150)");
}

const char* Form::GradeTooLowException::what() const throw(){
    return ("Grade value out of range ! (1-150)");
}

std::ostream    &operator<<(std::ostream &os, const Form &form)
{
    os << "The form : " << form.getName();
    if (form.getSigned())
        os << " is signed. ";
    else
        os << " is unsigned. ";
    os << "The grade to sign it is : " << form.getRequireToSign() << " and the grade to exec it is : " << form.getRequireToExec() << ".";
    return (os);
}
