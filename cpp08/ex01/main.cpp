#include "Span.hpp"
#include <iostream>

int main()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "ShortestSpan : " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan : " << sp.longestSpan() << std::endl;
    
    
    return 0;
}

