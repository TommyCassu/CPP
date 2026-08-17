#include "RPN.hpp"

int main(int ac, char *av[]) {
    if (ac != 2 || av[1][0] == '\0') {
        std::cerr << "Error : Usage -> ./RPN \"expression\"" << std::endl;
        return (1);
    }
    try {
        RPN test;
        std::cout << test.process(av[1]) << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
