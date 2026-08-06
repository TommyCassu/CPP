#include "Span.hpp"
#include <iostream>

int main()
{
    try {
        std::cout << "Test with 6,3,17,9,11 :" << std::endl;
        Span sp = Span(10);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);

        std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::vector<int> sc;
        std::cout << "Test with 10000 :" << std::endl;
        for (int i = 0; i < 10000; i++)
            sc.push_back(std::rand());
        Span sp2 = Span(10000);
        sp2.addNumbers(sc.begin(), sc.end());
        std::cout << "ShortestSpan : " << sp2.shortestSpan() << std::endl;
        std::cout << "longestSpan : " << sp2.longestSpan() << std::endl;
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;

    try {
        std::cout << "Test addNumber on full Span :" << std::endl;
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(12);
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << std::endl;
    try {
        std::cout << "Test Span empty :" << std::endl;
        Span sp = Span(5);
        std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "Test addNumber on full Span :" << std::endl;
        Span sp = Span(3);
        sp.addNumber(2147483647);
        sp.addNumber(-2147483648);
        sp.addNumber(0);
        std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
        std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "Test Span empty :" << std::endl;
        Span sp = Span(5);
        std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    std::cout << std::endl;
    try {
        std::cout << "Test Span empty :" << std::endl;
        Span sp = Span(5);
        std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
    } catch ( std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

