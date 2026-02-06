#include "ScalarConverter.hpp"
#include <algorithm>
#include <sstream>
#include <limits.h>

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

const char* ScalarConverter::InvalidInputException::what() const throw() {
    return ("Error ! Invalid input. Please verify your input !");
}

enum TypeFounded { CHAR, INT, FLOAT, DOUBLE, UNKNOW };

int countOccurence(std::string str, char c) {
    int count = 0;
    for (int i = 0; i < str.length(); i++)
        if (tolower(str[i]) == c)
            count++;
    return count;
}

int getInt(std::string str) {
    std::istringstream stream(str);
    int returnedInt;
    if (stream >> returnedInt)
        return returnedInt;
    return 0;
}

double getDouble(std::string str) {
    std::istringstream stream(str);
    double returnedDouble;
    if (stream >> returnedDouble)
        return returnedDouble;
    return 0;
}

float getFloat(std::string str) {
    std::istringstream stream(str);
    float returnedFloat;
    if (stream >> returnedFloat)
        return returnedFloat;
    return 0;
}

void    printChar(std::string value) {
    if (value.length() == 1) {
        if ((!isdigit(static_cast<unsigned char>(value[0]))) && isprint(static_cast<unsigned char>(value[0])))
            std::cout << static_cast<char>(value[0]) << std::endl;
        if (!isprint(static_cast<unsigned char>(value[0])))
            throw ScalarConverter::InvalidInputNoPrintableException();
    }
    else {
        double returnedInt = getDouble(value);
        if (returnedInt > INT_MAX || returnedInt < INT_MIN)
            std::cout << "char: Non displayable" << std::endl;
        else if (isprint(static_cast<unsigned char>(value[0])))
            std::cout << static_cast<char>(value[0]) << std::endl;
    }
}

void    printInt(std::string value) {
    double returnedInt = getDouble(value);
        std::cout << returnedInt << std::endl;
    if (returnedInt < INT_MIN || INT_MAX)
        std::cout << "int: impossible (out of limits)" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(returnedInt) << std::endl;
}

TypeFounded parsingString(std::string value) {
    
    if (value.length() == 1) {
        if ((!isdigit(static_cast<unsigned char>(value[0]))) && isprint(static_cast<unsigned char>(value[0])))
            return (CHAR);
        if (!isprint(static_cast<unsigned char>(value[0])))
            throw ScalarConverter::InvalidInputNoPrintableException();
    }
    if (getInt(value)) {
        return INT;
    }
    int nb_f = countOccurence(value, 'f');
    int nb_dot = countOccurence(value, '.');
    if ((nb_f == 1 && nb_dot == 1 && getFloat(value))) {
        return FLOAT;
    }
    if ((nb_f == 0 && nb_dot == 1 && getDouble(value))  || getInt(value)){
        return DOUBLE;
    }
    
    return INT;
};

void    ScalarConverter::convert(std::string const &value) {
    try {
        TypeFounded type = parsingString(value);
        float floatResult;
        double doubleResult;
        switch (type) {
            case CHAR:
                std::cout << "char: " << value[0] << std::endl;
                std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
                std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
                break;
            case INT: {
                printChar(value);
                printInt(value);
                //std::cout << "float: " << static_cast<float>(returnedInt) << ".0f" << std::endl;
                //std::cout << "double: " << static_cast<double>(returnedInt) << ".0" << std::endl;
                break;
            }
            case FLOAT:
                std::cout << "char : Non displayable" << std::endl;
                std::cout << "int: " << getInt(value) << std::endl;
                std::cout << "float: " << getFloat(value) << "f" << std::endl;
                std::cout << "double: " << getDouble(value) << std::endl;
                break;
            case DOUBLE:
                std::cout << "char : Non displayable" << std::endl;
                std::cout << "int: " << getInt(value) << std::endl;
                std::cout << "float: " << getFloat(value) << "f" << std::endl;
                std::cout << "double: " << getDouble(value) << std::endl;
                break;
            case UNKNOW:
                throw InvalidInputException();
        }

    } catch (const std::exception &e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }  
}