#include "ScalarConverter.hpp"

int main() {

    // Test avec un entier
    std::cout << "Test avec un entier:"  << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;

    std::cout << "Test avec un entier:"  << std::endl;
    ScalarConverter::convert("A");
    std::cout << std::endl;

    std::cout << "Test avec un entier:"  << std::endl;
    ScalarConverter::convert("5");
    std::cout << std::endl;

    std::cout << "Test avec un entier:"  << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;
    // Test avec un flottant
    std::cout << "Test avec un flottant:"  << std::endl;
    ScalarConverter::convert("42.42");
    std::cout << std::endl;

    // Test avec un double
    std::cout << "Test avec un double:"  << std::endl;
    ScalarConverter::convert("42.4242");
    std::cout << std::endl;

    // Test avec une valeur non numérique
    std::cout << "Test avec une valeur non numérique:"  << std::endl;
    ScalarConverter::convert("abc");
    std::cout << std::endl;

    // Test avec une valeur NaN
    std::cout << "Test avec une valeur NaN:"  << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;

    // Test avec une valeur infinie
    std::cout << "Test avec une valeur infinie:"  <<  std::endl;
    ScalarConverter::convert("inf");
    std::cout << std::endl;

    return 0;
}