#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {
    std::ifstream istrm("data.csv");

    if (!istrm.is_open())
        throw std::runtime_error("Error : could not open database file data.csv");

    std::string header;
    std::getline(istrm, header, '\n');
    for (std::string line; std::getline(istrm, line, '\n');) {
        size_t separator = line.find(",");
        if (separator != std::string::npos) {
            std::string key = line.substr(0, separator);
            std::string value = line.substr(separator + 1);
            this->input_csv[key] = std::atof(value.c_str()) ;
        }
        else
            std::cerr << "Error: bad input in data.csv => " << line << std::endl;
    }

    if (this->input_csv.empty())
        throw std::runtime_error("Error : database data.csv is empty or unreadable");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &btc) {
    *this = btc;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &btc) {
    if (this != &btc)
        this->input_csv = btc.input_csv;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {};

static int onlyDigit(std::string value) {
    for (size_t i = 0; i < value.size(); i++)
        if (!isdigit(value[i]))
            return 1;
    return 0;
}
static int isValidNumber(std::string value) {
    size_t i = 0;
    int digits = 0;
    int dots = 0;

    if (value.empty())
        return 0;
    if (value[i] == '+' || value[i] == '-')
        i++;
    for (; i < value.size(); i++) {
        if (isdigit(static_cast<unsigned char>(value[i])))
            digits++;
        else if (value[i] == '.' && dots == 0)
            dots++;
        else
            return 0;
    }
    return (digits > 0);
}

static  int checkDate(std::string date) {
    
    // format XXXX-XX-XX
    if (date.length() != 10 || (!(date[4] == '-' && date[7] == '-'))) {
        return 1;
    }
    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (onlyDigit(year) || onlyDigit(month) || onlyDigit(day))
        return 1;
    
    int yearInt = std::atoi(year.c_str());
    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());
    // verif annee bisextil, nb mois, nb jour par mois
    int nbDaysPerMonths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0))
        nbDaysPerMonths[1] = 29;
    if (monthInt < 1 || monthInt > 12)
        return 1;
    if (dayInt < 1 || dayInt > nbDaysPerMonths[monthInt - 1])
        return 1;
    return (0);
};

double BitcoinExchange::getDateValue(std::string date) {

    std::map<std::string, double>::iterator it = input_csv.upper_bound(date);

    if (it == input_csv.begin()) {
        std::cerr << "Error : Date too old, no info for this actual periode" << std::endl;
        return -1.0f;
    }
    it--;
    return it->second;
}

void    BitcoinExchange::processingData(std::string file) {
   std::ifstream istrm(file.c_str());
   if (!istrm.is_open()) {
        std::cerr << "Error : could not open file." << std::endl;
   } else {
    std::string line;
    std::getline(istrm, line, '\n');
    if (line != "date | value") {
        std::cerr << "Error : Bad format data enter => " << line << std::endl;
    }
    while(std::getline(istrm, line, '\n')) {
        size_t separator = line.find(" | ");
        if (separator == std::string::npos) {
            std::cerr << "Error : Bad input separator => " << line << std::endl;
        } else {
            std::string key = line.substr(0, separator);
            std::string value = line.substr(separator + 3);
            if (checkDate(key)) {
                std::cerr << "Error : Bad date enter => " << key << std::endl;
                continue ;
            }

            if (!isValidNumber(value)) {
                std::cerr << "Error : Bad value enter (not a number) " << value << std::endl;
                continue ;
            }

            double valueFloat = atof(value.c_str());

            if (valueFloat < 0) {
                std::cerr << "Error : Bad value enter (negative number) " << value << std::endl;
            } else if (valueFloat > 1000) {
                std::cerr << "Error : Bad value enter (Too large number) " << value << std::endl;
            } else {
                double result = BitcoinExchange::getDateValue(key);
                if (result >= 0) {
                    std::cout << key << " => " << value << " = " << (result * valueFloat) << std::endl;
                }
            }

        }
    }
    }
    istrm.close();
};