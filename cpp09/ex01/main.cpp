#include "RPN.hpp"

int main(int ac, char *av[]) {
    if (ac == 2) {
        try {
            RPN test;
            std::cout << test.process(av[1]) << std::endl;
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
        }
    } else {
        std::cout << "Error : Usage -> ./RPN \"expression\"" << std::endl;
    }
};