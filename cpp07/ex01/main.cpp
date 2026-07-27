#include "iter.hpp"
#include <iostream>


int main( void ) {
    int numsInt[4] = {1, 4, 5, 2};
    double numsDouble[4] = {1.1, 4.4, 5.5, 2.2};
    iter(numsInt, 4, print<int>);
    iter(numsInt, 4, add1<int>);
    std::cout << std::endl;
    iter(numsInt, 4, print<int>);
    std::cout << std::endl;
    iter(numsDouble, 4, print<double>);
    std::cout << std::endl;
    iter(numsDouble, 4, add1<double>);
    iter(numsDouble, 4, print<double>);

    return 0;
}
