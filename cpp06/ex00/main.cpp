#include "ScalarConverter.hpp"

int main() {

    // Test avec un entier
    std::cout << "Test avec \"a\""  << std::endl;
    ScalarConverter::convert("a");
    std::cout << std::endl;

    std::cout << "Test avec \"A\""  << std::endl;
    ScalarConverter::convert("A");
    std::cout << std::endl;

    std::cout << "Test avec \"5\""  << std::endl;
    ScalarConverter::convert("5");
    std::cout << std::endl;

    // Test avec un flottant
    std::cout << "Test avec \"42.42f\""  << std::endl;
    ScalarConverter::convert("42.42f");
    std::cout << std::endl;

    // Test avec un double
    std::cout << "Test avec \"42.4242\""  << std::endl;
    ScalarConverter::convert("42.4242");
    std::cout << std::endl;

    // Test avec une valeur non numérique
    std::cout << "Test avec une valeur non autorisee"  << std::endl;
    ScalarConverter::convert("abc");
    std::cout << std::endl;

    // Test avec une valeur NaN
    std::cout << "Test avec \"nan\""  << std::endl;
    ScalarConverter::convert("nan");
    std::cout << std::endl;

    // Test avec une valeur infinie
    std::cout << "Test avec \"-inf\""  <<  std::endl;
    ScalarConverter::convert("-inf");
    std::cout << std::endl;

    // Test avec une valeur infinie
    std::cout << "Test avec \"+inf\""  <<  std::endl;
    ScalarConverter::convert("+inf");
    std::cout << std::endl;

    // Test avec une valeur infinie
    std::cout << "Test avec \"-inff\""  <<  std::endl;
    ScalarConverter::convert("-inff");
    std::cout << std::endl;

    // Test avec une valeur infinie
    std::cout << "Test avec \"+inff\""  <<  std::endl;
    ScalarConverter::convert("+inff");
    std::cout << std::endl;

    // Test avec une valeur infinie
    std::cout << "Test avec \"nanf\""  <<  std::endl;
    ScalarConverter::convert("nanf");
    std::cout << std::endl;

    return 0;
}