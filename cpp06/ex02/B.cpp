#include "B.hpp"

B::B() : Base() {
    std::cout << "B constructor called" << std::endl;
}

B::~B() {
    std::cout << "B destructor called" << std::endl;
}