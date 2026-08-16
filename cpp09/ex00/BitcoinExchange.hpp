# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, double> input_csv;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &btc);
        BitcoinExchange &operator=(const BitcoinExchange &btc);
        void processingData(std::string file);
        double getDateValue(std::string date);
};
# endif