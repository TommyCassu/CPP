#include "Array.hpp"
#include <iostream>
#include <string>

int main( void ) {
    {
        try {
            Array<int> a(5);
            for (unsigned int i = 0; i < a.size(); i++) {
                a[i] = i;
            };
            std::cout << "Array print :" << std::endl;
            for (unsigned int i = 0; i < a.size(); i++) {
                std::cout << a[i] << " ";
            };
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error ! " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try {
            Array<double> a(5);
            for (unsigned int i = 0; i < a.size(); i++) {
                a[i] = static_cast<double>(i) + 0.5;
            };
            std::cout << "Array print :" << std::endl;
            for (unsigned int i = 0; i < a.size(); i++) {
                std::cout << a[i] << " ";
            };
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error ! " << e.what() << std::endl;
        }
    }
    std::cout << std::endl;
    {
        try {
            Array<int> a(10);
            for (unsigned int i = 0; i < 11; i++) {
                a[i] = i;
            };
            std::cout << "Array print :" << std::endl;
            for (unsigned int i = 0; i < a.size(); i++) {
                std::cout << a[i] << " ";
            };
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error ! " << e.what() << std::endl;
        }
        
    }

    std::cout << std::endl;
    {
        try {
            Array<int> a(0);
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error ! " << e.what() << std::endl;
        }

    }

    std::cout << std::endl;
    {
        // complex type test (std::string), required by the subject's
        // "simple and complex types" check
        try {
            Array<std::string> a(3);
            a[0] = "hello";
            a[1] = "world";
            a[2] = "!";
            std::cout << "Array print :" << std::endl;
            for (unsigned int i = 0; i < a.size(); i++) {
                std::cout << a[i] << " ";
            };
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error ! " << e.what() << std::endl;
        }
    }


    std::cout << std::endl;
    {
        try {
            Array<int> a(3);
            a[0] = 1;
            a[1] = 2;
            a[2] = 3;

            const Array<int> b(a);
            std::cout << "const array read :" << std::endl;
            for (unsigned int i = 0; i < b.size(); i++) {
                std::cout << b[i] << " ";
            };
            std::cout << std::endl;
        } catch (const std::exception& e) {
            std::cout << "Error ! " << e.what() << std::endl;
        }
    }

}
