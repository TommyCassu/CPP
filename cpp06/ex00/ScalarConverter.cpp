#include "ScalarConverter.hpp"

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

//enum TypeFounded { CHAR, INT, FLOAT, DOUBLE };

TypeFounded:: parsingString(std::string value) {
    
    
    
    // CHAR
    if (value.length() == 1 && !isdigit(static_cast<unsigned char>(value[0])) && !isprint(static_cast<unsigned char>(value[0])))
        throw ScalarConverter::InvalidInputNoPrintableException();
    if (value.length() == 1 && !isdigit(static_cast<unsigned char>(value[0])))
        return (TypeFounded::CHAR);
};



void    ScalarConverter::convert(std::string const &value) {
    try {
        TypeFounded type = parsingString(value);
        switch (type) {
            case TypeFoundedCHAR:
                std::cout << "char: " << value[0] << std::endl;
                std::cout << "int: " << static_cast<int>(value[0]) << std::endl;
                std::cout << "float: " << static_cast<float>(value[0]) << std::endl;
                std::cout << "double: " << static_cast<double>(value[0]) << std::endl;
        }

    } catch (const std::exception &e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }  
}