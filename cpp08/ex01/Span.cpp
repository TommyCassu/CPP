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
    if (_spanArray.size() == _maxInt)
        throw ArrayFullException();
    _spanArray.push_back(nb);
}

int Span::longestSpan() {
    return ((*std::max_element(_spanArray.begin(), _spanArray.end())) - (*std::min_element(_spanArray.begin(), _spanArray.end())));
}
    
int Span::shortestSpan() {
    std::vector<int> TempVector = _spanArray;
    std::sort(TempVector.begin(), TempVector.end());
    int result = (TempVector.at(1) - TempVector.at(0));
    for (int i = 1; i < static_cast<int>(TempVector.size() - 1); i++) {
        if ((TempVector.at(i + 1) - TempVector.at(i)) <  result)
            result = ((TempVector.at(i + 1) - TempVector.at(i)));
    };
    return result;
}