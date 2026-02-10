#include "C.hpp"

C::C() : Base() {
    std::cout << "C constructor called" << std::endl;
}

C::~C() {
    std::cout << "C destructor called" << std::endl;
}