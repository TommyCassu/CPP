#include "ScalarConverter.hpp"
#include <sstream>
#include <limits.h>
#include <string>
# include <cfloat>
#include <cmath>

ScalarConverter::ScalarConverter() {
    std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &oldScalarConverter) {
    std::cout << "ScalarConverter copy constructor called" << std::endl;
    (void)oldScalarConverter;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &oldScalarConverter) {
    std::cout << "ScalarConverter copy assignement operator constructor called" << std::endl;
    (void)oldScalarConverter;
    return *this;
}

ScalarConverter::~ScalarConverter() {
    std::cout << "ScalarConverter destructor called" << std::endl;
}

const char* ScalarConverter::InvalidInputNoPrintableException::what() const throw() {
    return ("Invalid char input. No printable char is forbidden !");
}

const char* ScalarConverter::InvalidInputException::what() const throw() {
    return ("Invalid input. Please verify your input !");
}

static double getDouble(std::string str) {
    std::istringstream stream(str);
    double returnedDouble;
    if (stream >> returnedDouble && (stream.peek() == -1 || stream.peek() == 'f')) {
        return returnedDouble;
    }
    throw ScalarConverter::InvalidInputException();
    return 0;
}

static void    printChar(double returnedDouble) {
    if (returnedDouble < 32 || returnedDouble > 126)
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: " << static_cast<char>(returnedDouble) << std::endl;
}

static void    printInt(std::string value, double returnedDouble) {
    if (value.length() == 1) {
        if (isdigit(value[0]))
            std::cout << "int: " << static_cast<int>(returnedDouble) << std::endl;
    }
    else {
        
        if (returnedDouble < INT_MIN || returnedDouble > INT_MAX)
            std::cout << "int: impossible (out of limits)" << std::endl;
        else
            std::cout << "int: " << static_cast<int>(returnedDouble) << std::endl;
    }
}

static void    printFloat(std::string value, double returnedDouble) {
    if (value.length() == 1 || returnedDouble == 0) {
        if (isdigit(value[0]))
            std::cout << "float: " << static_cast<float>(returnedDouble) << ".0f" << std::endl;
    }
    else {
        if (returnedDouble < -FLT_MAX || returnedDouble > FLT_MAX)
            std::cout << "float: impossible (out of limits)" << std::endl;
        else
            std::cout << "float: " << static_cast<float>(returnedDouble) << "f" << std::endl;
    }
}

static void    printDouble(std::string value, double returnedDouble) {
    if (value.length() == 1 || returnedDouble == 0) {
        if (isdigit(value[0]))
            std::cout << "double: " << static_cast<double>(returnedDouble) << ".0" << std::endl;
    }
    else {
        if (returnedDouble < -DBL_MAX || returnedDouble > DBL_MAX)
            std::cout << "double: impossible (out of limits)" << std::endl;
        else
            std::cout << "double: " << static_cast<double>(returnedDouble) << std::endl;
    }
}

static void    printFunny(std::string value) {
    if (value == "nan" || value == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        if (value.find('-') != std::string::npos) {
            std::cout << "float: -inff" << std::endl;
            std::cout << "double: -inf" << std::endl;
        }
        else {
            std::cout << "float: +inff" << std::endl;
            std::cout << "double: +inf" << std::endl;
        }
    }
}

static bool    isFunnyValue(std::string value) {
    return (value == "nan" || value == "nanf" || value == "-inf" || value == "+inf" || value == "-inff" || value == "+inff");
}

void    ScalarConverter::convert(std::string const &value) {
    
    double doubleResult;
    if (isFunnyValue(value))
        return printFunny(value);
    try {
        if (value.length() == 1) {
            if (!isdigit(value[0]) && isprint(static_cast<unsigned char>(value[0]))) {
                std::cout << "char: " << static_cast<char>(value[0]) << std::endl;
                std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
                std::cout << "float: " << static_cast<float>(value[0]) << ".0f" << std::endl;
                std::cout << "double: " << static_cast<double>(value[0]) << ".0" << std::endl;
                return ;
            }
            else if (!isprint(static_cast<unsigned char>(value[0])))
                throw ScalarConverter::InvalidInputNoPrintableException();
        };
        doubleResult = getDouble(value);
        printChar(doubleResult);
        printInt(value, doubleResult);
        printFloat(value, doubleResult);
        printDouble(value, doubleResult);
    } catch (const std::exception &e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }  
}