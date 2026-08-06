# ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class ArrayFullException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class ErrorSizeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
};

class Span {
    private:
        unsigned int _maxInt;
        std::vector<int> _spanArray;
    public:
        Span();
        Span(unsigned int maxInt);
        ~Span();
        Span(const Span &src);
        Span &operator=(const Span &src);
        void addNumber(int nb);
        unsigned int shortestSpan() const ;
        unsigned int longestSpan() const;
        const std::vector<int>& getArray() const;


        template<typename typeIt>
        void    addNumbers(typeIt it_begin, typeIt it_end) {
            std::vector<int> tmp(it_begin, it_end);
            if (_spanArray.size() + tmp.size() > _maxInt)
                throw ArrayFullException();
            _spanArray.insert(_spanArray.end(), tmp.begin(), tmp.end());
            return ;
        }
};
# endif