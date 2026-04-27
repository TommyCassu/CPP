# ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <iostream>

class RPN {
    private:
        std::stack<double> result;
    public:
        RPN();
        ~RPN();
        RPN(const RPN &old);
        RPN &operator=(const RPN &old);
        double process(std::string polishNotation);
};

# endif
