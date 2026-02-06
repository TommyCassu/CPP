#include "ScalarConverter.hpp"
#include <algorithm>
#include <sstream>
#include <limits.h>
# include <cfloat>
#include <cmath>

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
    if (stream >> returnedDouble && (stream.peek() == -1 || stream.peek() == 'f'))
        return returnedDouble;
    throw ScalarConverter::InvalidInputException();
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
    //gestion int 0-9
    if (value.length() == 1 && !isdigit(static_cast<unsigned char>(value[0]))) {
        if (isprint(static_cast<unsigned char>(value[0])))
            std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
        if (!isprint(static_cast<unsigned char>(value[0])))
            throw ScalarConverter::InvalidInputNoPrintableException();
    }
    else {
        double returnedDouble = getDouble(value);
        if (returnedDouble < 32 || returnedDouble > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: " << static_cast<char>(returnedDouble) << std::endl;
    }
}

void    printInt(std::string value) {
    double returnedDouble = getDouble(value);
    if (value.length() == 1) {
        if (!isdigit(value[0]))
            std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
        else
            std::cout << "int: " << static_cast<int>(returnedDouble) << std::endl;
    }
    else {
        
        if (returnedDouble < INT_MIN || returnedDouble > INT_MAX)
            std::cout << "int: impossible (out of limits)" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(returnedDouble) << std::endl;
    }
}

void    printFloat(std::string value) {
    double returnedDouble = getDouble(value);
    if (value.length() == 1) {
        if (!isdigit(value[0]))
            std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(returnedDouble) << ".0f" << std::endl;
    }
    else {
        if (returnedDouble < -FLT_MAX || returnedDouble > FLT_MAX)
            std::cout << "float: impossible (out of limits)" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(returnedDouble) << "f" << std::endl;
    }
}

void    printDouble(std::string value) {
    double returnedDouble = getDouble(value);
    if (value.length() == 1) {
        if (!isdigit(value[0]))
            std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(returnedDouble) << ".0" << std::endl;
    }
    else {
        if (returnedDouble < -DBL_MAX || returnedDouble > DBL_MAX)
            std::cout << "double: impossible (out of limits)" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(returnedDouble) << std::endl;
    }
}

void    printFunny(std::string value) {
    if (value == "nan" || value == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (value.find('-')) {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
    }
}

bool    isFunnyValue(std::string value) {
    return (value == "nan" || value == "nanf" || value == "-inf" || value == "+inf" || value == "-inff" || value == "+inff");
}

TypeFounded parsingString(std::string value) {
    
    if (value.length() == 1) {
        if ((!isdigit(static_cast<unsigned char>(value[0]))) && isprint(static_cast<unsigned char>(value[0])))
            return (CHAR);
        if (!isprint(static_cast<unsigned char>(value[0])))
            throw ScalarConverter::InvalidInputNoPrintableException();
    }
    
    int nb_f = countOccurence(value, 'f');
    int nb_dot = countOccurence(value, '.');
    if ((nb_f == 1 && nb_dot == 1 && getFloat(value))) {
        return FLOAT;
    }
    if ((nb_f == 0 && nb_dot == 1 && getDouble(value))){
        return DOUBLE;
    }
    if (getDouble(value)) {
        return INT;
    }
    return DOUBLE;
};

void    ScalarConverter::convert(std::string const &value) {
    
    double doubleResult;
    if (isFunnyValue(value))
        return printFunny(value);
    try {
        doubleResult = getDouble(value);
        printChar(value);
        printInt(value);
        printFloat(value);
        printDouble(value);
    } catch (const std::exception &e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }  
}