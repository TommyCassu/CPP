#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(50);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
    std::vector<int>::iterator it_begin = sp.getArray().begin();
    std::vector<int>::iterator it_end = sp.getArray().end();
    sp.addRandomNumbers(it_begin, it_end);
    return 0;
}

