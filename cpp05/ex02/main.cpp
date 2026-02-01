#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    {
        Bureaucrat employee("Albert", 10);
        ShrubberyCreationForm shrubberyForm("Form_24601");
        std::cout << "* Incrementationnal Test *" << std::endl;
        try {
            std::cout << shrubberyForm << std::endl;
            shrubberyForm.beSigned(employee);
            shrubberyForm.execute(employee);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    


    return (0);
}