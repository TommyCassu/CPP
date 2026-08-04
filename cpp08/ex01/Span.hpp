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
        Span(const Span &src);
        Span &operator=(const Span &src);
        void addNumber(int nb);
        int shortestSpan() const ;
        int longestSpan() const;
        const std::vector<int>& getArray() const;

        class ArrayFullException : public std::exception {
            public:
                virtual const char* what() const throw(){
                    return "Your array is already full. You can't add more number !";
                }
        };

        class ErrorSizeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw(){
                    return "Your array size is too low to give a shortest/longest !";
                }
        };

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