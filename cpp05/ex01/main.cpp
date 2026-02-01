#include "Bureaucrat.hpp"
#include "Form.hpp"

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
        std::cout << "* Decrementationnal above limite Test *" << std::endl;
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
    std::cout << std::endl;
    std::cout << "*===* Form *===*" << std::endl;
    std::cout << std::endl;
    {
        
        std::cout << "* Basic form *" << std::endl;
        try {
            Form f("Pedro", false , 1, 150);
            std::cout << f << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Form init Sign|Exec under *" << std::endl;
        std::cout << "Form f(\"Polli\", false , 1, 151);" << std::endl;
        try {
            Form f("Pollo", false , 1, 151);
            std::cout << f << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Form f(\"Polli\", false , 151, 1);" << std::endl;
        try {
            Form f("Polli", false , 151, 1);
            std::cout << f << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Form init Sign|Exec Above *" << std::endl;
        std::cout << "Form f(\"Polli\", false , 1, 0);" << std::endl;
        try {
            Form f("Pollo", false , 1, 0);
            std::cout << f << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        std::cout << "Form f(\"Polli\", false , 0, 1);" << std::endl;
        try {
            Form f("Polli", false , 0, 1);
            std::cout << f << std::endl;
    
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << std::endl;
        std::cout << "* Bureaucrat grade under requireGradeToSign *" << std::endl;
        try {
            Bureaucrat employee("Manager", 150);
            Form f("PedroForm", false , 1, 150);
            std::cout << employee << std::endl;
            std::cout << f << std::endl;
            employee.signForm(f);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    {
        std::cout << std::endl;
        std::cout << "* Bureaucrat grade can sign *" << std::endl;
        try {
            Bureaucrat employee("Manager", 10);
            Form f("PedroForm", false , 15, 150);
            std::cout << employee << std::endl;
            std::cout << f << std::endl;
            employee.signForm(f);
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }


    return (0);
}