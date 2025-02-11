#pragma once
#include <deque>
#include <string>

class RPN {
public:
    static int evaluate(const std::string& expression);

private:
    static bool isOperator(char ch);
    static int applyOperator(int a, int b, char op);
};
