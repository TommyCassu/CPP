#include "iter.hpp"
#include <iostream>


template<typename T>
void    print(T const& a) {
    std::cout << a << std::endl;
}

void add1(int& a){
    a++;
}
int main( void ) {
    int numsInt[4] = {1, 4, 5, 2};
    double numsDouble[4] = {1.1, 4.4, 5.5, 2.2};
    iter(numsInt, 4, add1);
    iter(numsInt, 4, print<int>);
    iter(numsDouble, 4, print<double>);
    return 0;
}
