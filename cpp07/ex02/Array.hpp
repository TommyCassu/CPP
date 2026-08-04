# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>

template<typename T>
class Array {
    private:
        T* _elements;
        unsigned int _size;
    public:
        Array() : _elements(new T[0]()), _size(0) {
            std::cout << "Array template default constructor called" << std::endl;
        };

        Array(unsigned int n) : _elements(new T[n]()), _size(n) {
            std::cout << "Array template param(s) constructor called" << std::endl;
        };

        Array(const Array &oldArray) : _elements(new T[oldArray._size]()), _size(oldArray._size) {
            for (unsigned int i = 0; i < _size; i++)
                _elements[i] = oldArray._elements[i];
            std::cout << "Array template Copy constructor called" << std::endl;
        };

        ~Array() { delete[] _elements;}

        Array& operator=(const Array &oldArray) {
            if (this != &oldArray) {
                delete[] _elements;
                _elements = new T[oldArray._size];
                _size = oldArray._size;
                for (unsigned int i = 0; i < _size; i++)
                    _elements[i] = oldArray._elements[i];
            }
            std::cout << "Array template assignment operator called" << std::endl;
            return *this;
        };
        
        class      OutOfRangeException : public std::exception{
            public:
                virtual const char* what() const throw() {
                    return ("Size input is out of range !");
                };
        };

        const T& operator[](unsigned int n) const {
            if (n >= _size)
                throw OutOfRangeException();
            return _elements[n];
        };

        T& operator[](unsigned int n) {
            if (n >= _size)
                throw OutOfRangeException();
            return _elements[n];
        };

        unsigned int size() const { return _size; };

};

# endif