#pragma once

#include <stack>
#include <string>
#include <stdexcept>
#include <iostream>

class RPN {
public:
    RPN();
    ~RPN();

    int evaluate(const std::string &expression);

private:
    std::stack<int> stack; // Используем std::stack вместо std::deque

    void performOperation(char op);
};
