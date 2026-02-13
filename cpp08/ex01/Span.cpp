#include "Span.hpp"

Span::Span() : _maxInt(__INT_MAX__) {
    std::cout << "Span default constructor called" << std::endl;
    
};

Span::Span(unsigned int maxInt) : _maxInt(maxInt){
    _spanArray.reserve(_maxInt);
    std::cout << "Span param(s) constructor called" << std::endl;
};

Span::~Span() {
    std::cout << "Span destructor called" << std::endl;
};

class ArrayFullException : public std::exception {
    public:
        virtual const char* what() const throw(){
            return "Your array is already full. You can't add more number !";
        }
};

void    Span::addNumber(int nb) {
    std::cout << _spanArray.size() << std::endl;
    if (_spanArray.size() == _maxInt)
        throw ArrayFullException();
    _spanArray.push_back(nb);
}

    