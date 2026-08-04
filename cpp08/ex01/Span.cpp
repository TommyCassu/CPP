#include "Span.hpp"
#include <limits>

Span::Span() : _maxInt(std::numeric_limits<int>::max()) {
    std::cout << "Span default constructor called" << std::endl;
    
};

Span::Span(unsigned int maxInt) : _maxInt(maxInt){
    _spanArray.reserve(_maxInt);
    std::cout << "Span param(s) constructor called" << std::endl;
};

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
};

Span::Span(const Span &src) {
    *this = src;
    std::cout << "Span Copy constructor called" << std::endl;
};

Span &Span::operator=(const Span &src) {
    if (this != &src){
        _maxInt = src._maxInt;
        _spanArray = src._spanArray;
    }
    std::cout << "Operator overload called" << std::endl;
    return *this;
};



void    Span::addNumber(int nb) {
    if (_spanArray.size() == _maxInt)
        throw ArrayFullException();
    _spanArray.push_back(nb);
}

const std::vector<int>& Span::getArray() const {
    return _spanArray;
}

int Span::longestSpan() const{
    if (_spanArray.size() < 2)
        throw ErrorSizeTooLowException();
    return ((*std::max_element(_spanArray.begin(), _spanArray.end())) - (*std::min_element(_spanArray.begin(), _spanArray.end())));
}
    
int Span::shortestSpan() const{
    if (_spanArray.size() < 2)
        throw ErrorSizeTooLowException();
    std::vector<int> TempVector = _spanArray;
    std::sort(TempVector.begin(), TempVector.end());
    int result = (TempVector.at(1) - TempVector.at(0));
    for (unsigned int i = 1; i < (TempVector.size() - 1); i++) {
        if ((TempVector.at(i + 1) - TempVector.at(i)) <  result)
            result = ((TempVector.at(i + 1) - TempVector.at(i)));
    };
    return result;
}