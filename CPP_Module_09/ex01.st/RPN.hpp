#pragma once

#include <stack>
#include <string>
#include <stdexcept>
#include <iostream>

class RPN {
public:
    RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);
    ~RPN();

    int evaluate(const std::string &expression);

private:
    std::stack<int> stack;

    void performOperation(char op);
};
