# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>

class BitcoinExchange {
    private:
        std::map<std::string, float> input_csv;
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &btc);
        BitcoinExchange &operator=(const BitcoinExchange &btc);
        void processingData(std::string file);
        float getDateValue(std::string date);
};
# endif