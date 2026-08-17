#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main (int ac, char **av) {
    if (ac != 2) {
        std::cerr << "Error : Please enter a param file." << std::endl;
        return (1);
    }
    try {
        BitcoinExchange Btc;
        Btc.processingData(av[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return (1);
    }
    return (0);
}
