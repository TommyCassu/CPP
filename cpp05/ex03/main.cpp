#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


int main()
{
    {
        
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
    
    


    return (0);
}