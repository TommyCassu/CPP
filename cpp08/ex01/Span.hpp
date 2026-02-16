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
        void    addRandomNumbers(std::vector<int>::iterator it_begin, std::vector<int>::iterator it_end);
        int shortestSpan();
        int longestSpan();
        std::vector<int>& getArray();
        class      ErrorException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return ("Error test");
                };
        };
};
# endif