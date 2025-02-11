#pragma once

#include <deque>
#include <string>
#include <stdexcept>
#include <iostream>

class RPN {
public:
    RPN();
    ~RPN();

    int evaluate(const std::string &expression);

private:
    std::deque<int> deque;

    void performOperation(char op);
};
