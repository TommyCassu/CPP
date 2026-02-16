# ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class Span {
    private:
        unsigned int _maxInt;
        std::vector<int> _spanArray;
    public:
        Span();
        Span(unsigned int maxInt);
        ~Span();
        void addNumber(int nb);
        int shortestSpan();
        int longestSpan();

};
# endif