#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <deque>

int main( void ) {
    std::vector<int> myarray;

    myarray.push_back(1);
    myarray.push_back(2);
    myarray.push_back(3);

    try {
        std::cout << "   ### With occurrence ###" << std::endl;
        std::cout << "Occurrence found is : " << *easyfind(myarray, 1) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "   ### With no occurrence ###" << std::endl;
        easyfind(myarray, 10);
        std::cout << "Error ! nothing was thrown" << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "   ### std::list ###" << std::endl;
        std::list<int> mylist;
        mylist.push_back(10);
        mylist.push_back(20);
        mylist.push_back(30);
        std::cout << "Occurrence found is : " << *easyfind(mylist, 20) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "   ### std::deque ###" << std::endl;
        std::deque<int> mydeque;
        mydeque.push_back(7);
        mydeque.push_back(8);
        mydeque.push_back(9);
        std::cout << "Occurrence found is : " << *easyfind(mydeque, 9) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }

    std::cout << std::endl;
    try {
        std::cout << "   ### Negative values ###" << std::endl;
        std::vector<int> neg;
        neg.push_back(-42);
        neg.push_back(0);
        neg.push_back(42);
        std::cout << "Occurrence found is : " << *easyfind(neg, -42) << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error ! " << e.what() << std::endl;
    }

    return 0;
}
