# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", false, 145, 137), _target("DefaultTarget") {
    std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm(target, false, 145, 137), _target(target) {
    std::cout << "ShrubberyCreationForm param(s) constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &oldShrubberyCreationForm) : AForm(oldShrubberyCreationForm.getName(), oldShrubberyCreationForm.getSigned(), oldShrubberyCreationForm.getRequireToSign(), oldShrubberyCreationForm.getRequireToExec()) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& oldShrubberyCreationForm) {
     std::cout << "ShrubberyCreationForm Copy assignement operator called" << std::endl;
    if (this != &oldShrubberyCreationForm)
        this->_target = oldShrubberyCreationForm._target;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const {
    if (this->getSigned() == false)
        throw FormIsNotSignedException() ;
    else if (executor.getGrade() > this->getRequireToExec())
        throw GradeTooLowException() ;
    else {
        std::string filename = _target + "_Shrubbery";
        std::ofstream _File(filename.c_str());
        //if (!_File.is_open())
    
        _File << "                                                   |\n"
            << "                                              -x-\n"
            << "                                               |\n"
            << "              v .   ._, |_  .,\n"
            << "           `-._\\/  .  \\ /    |/_\n"
            << "               \\  _\\, y | \\//\n"
            << "         _\\_.___\\, \\/ -.\\||\n"
            << "           `7-,--.`._||  / / ,\n"
            << "           /'     `-. `./ / |/_.'\n"
            << "                     |    |//\n"
            << "                     |_    /\n"
            << "                     |-   |\n"
            << "                     |   =|\n"
            << "                     |    |\n"
            << "--------------------/ ,  . \\--------._\n";
            _File.close();
    };
    return ;
}