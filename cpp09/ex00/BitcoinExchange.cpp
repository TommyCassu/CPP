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
                //std::cout << key << " => " << this->input_csv[key] << std::endl;
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
    
    // format XXXX-XX-XX
    if (date.length() > 10 || (!(date[4] == '-' && date[7] == '-'))) {
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
    int nbDaysPerMonths[] = {31, 28, 31, 30, 31, 30, 32, 31, 30, 31, 30, 31};
    if ((yearInt % 4 == 0 && yearInt % 100 != 0) || (yearInt % 400 == 0))
        nbDaysPerMonths[1] = 29;
    if (monthInt < 0 || monthInt > 12)
        return 1;
    if (dayInt < 0 || dayInt > nbDaysPerMonths[monthInt - 1])
        return 1;
    return (0);
};

float BitcoinExchange::getDateValue(std::string date) {
    
    std::string previousDate;
    float previousValue = 0;

    std::map<std::string, float>::iterator it;
    for (it = input_csv.begin(); it != input_csv.end(); it++) {
        const std::string &presentDate = it->first;
        float presentValue = it->second;
        if (previousDate.empty() && date < presentDate) {
            std::cout << "Error : Date too old, no info for this actual periode" << std::endl;
            return -1.0f;
        }
        if (presentDate > date)
            break ;
        previousDate = presentDate;
        previousValue = presentValue;
    }
    return previousValue;
}

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
            std::string value = line.substr(separator + 3);
            if (checkDate(key)) {
                std::cout << "Error : Bad date enter => " << key << std::endl;
            }

            float valueFloat = atof(value.c_str());

            if (valueFloat < 0) {
                std::cout << "Error : Bad value enter (negative number) " << value << std::endl;
            } else if (valueFloat > 1000) {
                std::cout << "Error : Bad value enter (Too large number) " << value << std::endl;
            } else {
                float result = BitcoinExchange::getDateValue(key);
                if (result >= 0) {
                    std::cout << key << " => " << value << " = " << (result * valueFloat) << std::endl;
                }
            }

        }
    }
    }
    istrm.close();
};