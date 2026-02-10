#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <ctime>
#include <cstdlib>


Base::~Base(void) {
    std::cout << "Base destructor called" << std::endl;
}

Base* generate(void) {
    std::srand(std::time(0));
    int i = std::rand() % 3;
    switch (i) {
        case 0: {
            A *newBase = new A();
            return newBase;
        }
        case 1: {
            B *newBase = new B();
            return newBase;
        }
        case 2: {
            C *newBase = new C();
            return newBase;
        }
    }
    return NULL;
}

void    identify(Base* p) {
    std::cout << "Identification with Base* p" << std::endl;
    if (dynamic_cast<A*>(p))
        std::cout << "p: A" <<std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "p: B" <<std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "p: C" <<std::endl;
}

void    identify(Base& p) {
    std::cout << "Identification with Base& p" << std::endl;
    try {
        dynamic_cast<A&>(p);
        std::cout << "p: A" <<std::endl;
    } catch (std::exception& e) {
        try {
            dynamic_cast<B&>(p);
            std::cout << "p: B" <<std::endl;
        } catch (std::exception& e) {
            dynamic_cast<C&>(p);
            std::cout << "p: C" <<std::endl;
        } 
    }
    
}