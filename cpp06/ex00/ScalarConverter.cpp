#include "ScalarConverter.hpp"
#include <algorithm>

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &oldScalarConverter) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &oldScalarConverter) {
    std::cout << "ScalarConverter copy assignement operator constructor called" << std::endl;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

const char* ScalarConverter::InvalidInputNoPrintableException::what() const throw() {
    return ("Error ! Invalid char input. No printable char is forbidden !");
}

enum TypeFounded { CHAR, INT, FLOAT, DOUBLE };

int countOccurence(std::string str, char c) {
    int count = 0;
    for (int i = 0; i < str.length(); i++)
        if (tolower(str[i]) == c)
            count++;
    return count;
}

TypeFounded parsingString(std::string value) {
    
    if (value.length() == 1) {
        if ((!isdigit(static_cast<unsigned char>(value[0]))) && isprint(static_cast<unsigned char>(value[0])))
            return (CHAR);
        if (!isprint(static_cast<unsigned char>(value[0])))
            throw ScalarConverter::InvalidInputNoPrintableException();
    }
    int nb_f = countOccurence(value, 'f');
    int nb_dot = countOccurence(value, 'f');
    if (nb_f == 1 && nb_dot == 1) {
        return FLOAT;
    }
    if (nb_f == 0 && nb_dot == 1) {
        return DOUBLE;
    }
    return (UNKNOW);
};



void    ScalarConverter::convert(std::string const &value) {
    try {
        TypeFounded type = parsingString(value);
        switch (type) {
            case CHAR:
                std::cout << "char: " << value[0] << std::endl;
                std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
                std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
            case INT:
                std::cout << "char: " << value[0] << std::endl;
                std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
                std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }  
}