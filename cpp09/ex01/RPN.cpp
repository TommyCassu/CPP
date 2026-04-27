#include "RPN.hpp"
#include <sstream>
#include <cstdlib>


RPN::RPN() {
}

RPN::~RPN() {
}

RPN::RPN(const RPN &old) {
    *this = old;
}

RPN &RPN::operator=(const RPN &old) {
    if (this != &old) {
        this->result = old.result;
    }
    return *this;
}

double processOperator(double a, double b, char operatorFound) {
    int output;
    switch (operatorFound) {
        case '+':
            output = (a + b);
            break ;
        case '-':
            output = (a - b);
            break ;
        case '*':
            output = (a * b);
            break ;
    }
    return output;
}

double RPN::process(std::string polishNotation) {
    std::istringstream ss(polishNotation);
    std::string token;
    while (ss >> token) {
        if (isdigit(token[0])) {
            this->result.push(std::atoi(token.c_str()));
        } else {
            if (result.size() >= 2) {
                double b = this->result.top();
                this->result.pop();
                double a = this->result.top();
                this->result.pop();
                if (token[0] == '+' || token[0] == '-' || token[0] == '*') {
                    this->result.push(processOperator(a, b, token[0]));
                } else if (token [0] == '/') {
                    if (b == 0) {
                        throw std::runtime_error("Error :  A number can't be divided by Zero");
                    }
                    this->result.push(a / b);
                }
            } else {
                throw std::runtime_error("Error : Invalid reverse polish expression enter");
            }
        } 
    }
    return this->result.top();
}
