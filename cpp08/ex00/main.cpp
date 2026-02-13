#include "easyfind.hpp"
#include <iostream>

int main( void ) {
    std::vector<int> myarray;

    myarray.push_back(1);
    myarray.push_back(2);
    myarray.push_back(3);
    std::cout << "Test with occurrence :" << std::endl;
    try {
        std::cout << "Occurrence found is : " << *easyfind(myarray, 1) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }
        std::cout << "Test with no occurrence :" << std::endl;

    try {
        easyfind(myarray, 10);
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }
}
