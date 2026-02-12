# include "AForm.hpp"
# include "Bureaucrat.hpp"

AForm::AForm() : _name("DefaultFormName"), _isSigned(0), _requiredGradeToSign(150), _requiredGradeToExec(150) {
    std::cout << "Form default constructor called" << std::endl;
}

AForm::AForm(const std::string name, bool isSigned, const int requiredGradeToSign, const int requiredGradeToExec) : _name(name), _isSigned(isSigned), _requiredGradeToSign(requiredGradeToSign), _requiredGradeToExec(requiredGradeToExec) {
    std::cout << "Form param(s) constructor called" << std::endl;
    if (requiredGradeToSign < 1 || requiredGradeToExec < 1)
        throw GradeTooHighException();
    else if (requiredGradeToSign > 150 || requiredGradeToExec > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &oldForm) : _name(oldForm._name), _isSigned(oldForm._isSigned), _requiredGradeToSign(oldForm._requiredGradeToSign), _requiredGradeToExec(oldForm._requiredGradeToExec) {
    std::cout << "Form copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm& oldForm) {
     std::cout << "Form Copy assignement operator constructor called" << std::endl;
    if (this != &oldForm)
        _isSigned = oldForm._isSigned;
    return *this;
}

AForm::~AForm() {
    std::cout << "Form destructor called" << std::endl;
}

std::string AForm::getName() const {
    return _name;
}

bool    AForm::getSigned() const {
    return _isSigned;
}

int     AForm::getRequireToSign() const {
    return _requiredGradeToSign;
}

int     AForm::getRequireToExec() const {
    return _requiredGradeToExec;
}

void    AForm::beSigned(Bureaucrat &bureaucrat) {
    if (bureaucrat.getGrade() > _requiredGradeToSign)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw(){
    return ("Bureaucrat grade is too high ! (1-150)");
}

const char* AForm::GradeTooLowException::what() const throw(){
    return ("Bureaucrat grade is too low !");
}

const char* AForm::FormIsNotSignedException::what() const throw(){
    return ("You can't execute a form not signed !");
}

std::ostream    &operator<<(std::ostream &os, const AForm &aform)
{
    os << "The form : " << aform.getName();
    if (aform.getSigned())
        os << " is signed. ";
    else
        os << " is unsigned. ";
    os << "The grade to sign it is : " << aform.getRequireToSign() << " and the grade to exec it is : " << aform.getRequireToExec() << ".";
    return (os);
}

void    AForm::execute(Bureaucrat const & executor) const {
    if (this->getSigned() == false)
        throw FormIsNotSignedException() ;
    else if (executor.getGrade() > this->getRequireToExec())
        throw GradeTooLowException() ;
    executeThisForm();
}
