# ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template<typename T, typename F>
void    iter(T* arrayAddr, size_t Lenght, F function) {
    if (!arrayAddr || !function)
        return ;
    for (size_t i = 0; i < Lenght; i++) {
        function(arrayAddr[i]);
    }
    return ;
};

template<typename T>
void    print(T const& a) {
    std::cout << a << " ";
};

template<typename T>
void add1(T& a){
    ++a;
};
# endif