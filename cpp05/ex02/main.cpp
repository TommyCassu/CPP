#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    {
        std::cout << "* ShrubberyCreation Test *" << std::endl;
        Bureaucrat employee("Albert", 136);
        ShrubberyCreationForm shrubberyForm("Form_24601");
        try {
            std::cout << shrubberyForm << std::endl;
            employee.signForm(shrubberyForm);
            shrubberyForm.execute(employee);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "* RobotomyRequest Test *" << std::endl;
        Bureaucrat employee("Albert", 45);
        RobotomyRequestForm robotomyForm("Form_24601");
        try {
            std::cout << robotomyForm << std::endl;
            employee.signForm(robotomyForm);
            robotomyForm.execute(employee);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "* PresidentialPardon Test *" << std::endl;
        Bureaucrat employee("Albert", 4);
        PresidentialPardonForm presidentialForm("Fabrice");
        try {
            std::cout << presidentialForm << std::endl;
            employee.signForm(presidentialForm);
            presidentialForm.execute(employee);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        std::cout << "* PresidentialPardon Fail Test *" << std::endl;
        Bureaucrat employee("Albert", 8);
        PresidentialPardonForm presidentialForm("Fabrice");
        try {
            std::cout << presidentialForm << std::endl;
            employee.signForm(presidentialForm);
            presidentialForm.execute(employee);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    


    return (0);
}