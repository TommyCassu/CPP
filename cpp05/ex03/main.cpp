#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    
    {
        std::cout << "*** Intern Shrubbery Test ***" << std::endl;
        try {
            Bureaucrat employee("Albert", 4);
            Intern randomSouffifre;
            AForm *rrf;
            rrf = randomSouffifre.makeForm("shrubbery creation", "Home");
            std::cout << *rrf << std::endl;
            std::cout << employee << std::endl;
            employee.signForm(*rrf);
            employee.executeForm(*rrf);
            delete rrf;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "*** Intern Robotomy Test ***" << std::endl;
        
        try {
            Bureaucrat employee("Albert", 4);
            Intern randomSouffifre;
            AForm *rrf;
            rrf = randomSouffifre.makeForm("robotomy request", "Home");
            std::cout << *rrf << std::endl;
            std::cout << employee << std::endl;
            employee.signForm(*rrf);
            employee.executeForm(*rrf);
            delete rrf;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "*** Intern Presidential Test ***" << std::endl;
        
        try {
            Bureaucrat employee("Albert", 4);
            Intern randomSouffifre;
            AForm *rrf;
            rrf = randomSouffifre.makeForm("presidential pardon", "Home");
            std::cout << *rrf << std::endl;
            std::cout << employee << std::endl;
            employee.signForm(*rrf);
            employee.executeForm(*rrf);
            delete rrf;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    std::cout << std::endl;
    {
        std::cout << "*** Intern Failed Test ***" << std::endl;
        
        try {
            Bureaucrat employee("Albert", 150);
            Intern randomSouffifre;
            AForm *rrf;
            rrf = randomSouffifre.makeForm("presidential pardon", "Home");
            std::cout << *rrf << std::endl;
            std::cout << employee << std::endl;
            employee.signForm(*rrf);
            employee.executeForm(*rrf);
            delete rrf;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    


    return (0);
}