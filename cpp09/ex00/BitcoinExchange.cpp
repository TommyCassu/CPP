#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {
    std::ifstream istrm("data.csv");
    if (istrm.is_open()) {
        for (std::string line; std::getline(istrm, line, '\n');) {
            int separator = line.find(",");
            if (separator != -1) {
                std::string key = line.substr(0, separator);
                std::string value = line.substr(separator + 1);
                this->input_csv[key] = std::atof(value.c_str()) ;
                std::cout << this->input_csv[key] << std::endl;
            }
            else
                std::cout << "Error: bad input in data.csv => " << line << std::endl;
            
        };
    } else
        std::cout << "Error : Pleaser enter a valid file" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {};