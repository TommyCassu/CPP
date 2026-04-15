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
                std::cout << key << " => " << this->input_csv[key] << std::endl;
            }
            else
                std::cout << "Error: bad input in data.csv => " << line << std::endl;
            
        };
    } else
        std::cout << "Error : Pleaser enter a valid file" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {};

static int onlyDigit(std::string value) {
    for (size_t i = 0; i < value.size(); i++)
        if (!isdigit(value[i]))
            return 1;
    return 0;
}
static  int checkDate(std::string date) {
    //int months[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    //int nbDaysPerMonths[] {31, 28, 31, 30, 31, 31, 30, 31, 30, 31};
    // format XXXX-XX-XX
    if (date.length() > 10 || (!(date[4] == '-' && date[7] == '-'))) {
        std::cout << "Error : Bad date format enter => " << date << std::endl;
        return 1;
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (onlyDigit(year) || onlyDigit(month) || onlyDigit(day))
        std::cout << "Error : Bad date enter => " << date << std::endl;
    
    return (0);
};

void    BitcoinExchange::processingData(std::string file) {
   std::ifstream istrm(file.c_str());
   if (!istrm.is_open()) {
        std::cout << "Error : Pleaser enter a valid file" << std::endl;
   } else {
    std::string line;
    std::getline(istrm, line, '\n');
    if (line != "date | value") {
        std::cout << "Error : Bad format data enter => " << line << std::endl;
    }
    while(std::getline(istrm, line, '\n')) {
        size_t separator = line.find(" | ");
        if (separator == std::string::npos) {
            std::cout << "Error : Bad input separator => " << line << std::endl;
        } else {
            std::string key = line.substr(0, separator);
            if (checkDate(key)) {
                //std::cout << "Error : Bad format date enter => " << key << std::endl;
            }
        }

    }


    }
};