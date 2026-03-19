#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <string>

int main (int ac, char **av) {
    if (ac == 2)
    {
        (void)av;
       BitcoinExchange BitcoinExchange; 
    } else 
        std::cout << "Error : Please enter a param file.)" << std::endl;
    return (0);
}