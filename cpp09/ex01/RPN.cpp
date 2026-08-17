#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <stdexcept>


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

static int isOperator(const std::string &token) {
    return (token.size() == 1 && (token[0] == '+' || token[0] == '-'
            || token[0] == '*' || token[0] == '/'));
}

static int isNumber(const std::string &token) {
    if (token.size() != 1)
        return 0;
    if (!isdigit(static_cast<unsigned char>(token[0])))
        return 0;
    return 1;
}

static double processOperator(double a, double b, char operatorFound) {
    double output = 0;
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
        case '/':
            output = (a / b);
            break ;
    }
    return output;
}

double RPN::process(std::string polishNotation) {
    std::istringstream ss(polishNotation);
    std::string token;

    while (!this->result.empty())
        this->result.pop();
    while (ss >> token) {
        if (isNumber(token)) {
            this->result.push(std::atoi(token.c_str()));
        } else if (isOperator(token)) {
            if (this->result.size() < 2)
                throw std::runtime_error("Error : Invalid reverse polish expression enter");
            double b = this->result.top();
            this->result.pop();
            double a = this->result.top();
            this->result.pop();
            if (token[0] == '/' && b == 0)
                throw std::runtime_error("Error :  A number can't be divided by Zero");
            this->result.push(processOperator(a, b, token[0]));
        } else {
            throw std::runtime_error("Error : Invalid token in expression => " + token);
        }
    }
    if (this->result.size() != 1)
        throw std::runtime_error("Error : Invalid reverse polish expression enter");
    return this->result.top();
}
