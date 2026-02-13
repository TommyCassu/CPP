#include "Bureaucrat.hpp"

int main()
{
    {
        std::cout << "* Incrementationnal Test *" << std::endl;
        try {
            Bureaucrat employee("Albert", 10);
            std::cout << employee << std::endl;
            employee.incrementGrade();
            std::cout << employee << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Decrementationnal Test *" << std::endl;
        try {
            Bureaucrat employee("Philipe", 10);
            std::cout << employee << std::endl;
            employee.decrementGrade();
            std::cout << employee << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Decrementationnal under limite Test *" << std::endl;
        try {
            Bureaucrat employee("Jason", 150);
            std::cout << employee << std::endl;
            employee.decrementGrade();
            std::cout << employee << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Incrementationnal above limite Test *" << std::endl;
        try {
            Bureaucrat employee("Richie", 1);
            std::cout << employee << std::endl;
            employee.incrementGrade();
            std::cout << employee << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Initialization under limite Test *" << std::endl;
        try {
            Bureaucrat employee("Marc", 151);
            std::cout << employee << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Initialization above limite Test *" << std::endl;
        try {
            Bureaucrat employee("Pedro", 0);
            std::cout << employee << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return (0);
}