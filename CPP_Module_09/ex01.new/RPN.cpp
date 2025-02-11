#include "RPN.hpp"
#include <sstream>
#include <stdexcept>
#include <iostream>

bool RPN::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/';
}

int RPN::applyOperator(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: throw std::invalid_argument("Invalid operator");
    }
}

int RPN::evaluate(const std::string& expression) {
    std::deque<int> deque;
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (token.size() == 1 && isOperator(token[0])) {
            if (deque.size() < 2) {
                throw std::invalid_argument("Invalid expression");
            }
            int b = deque.back(); deque.pop_back();
            int a = deque.back(); deque.pop_back();
            int result = applyOperator(a, b, token[0]);
            deque.push_back(result);
        } else {
            std::istringstream tokenStream(token);
            int num;
            if (!(tokenStream >> num)) {
                throw std::invalid_argument("Invalid number");
            }
            deque.push_back(num);
        }
    }

    if (deque.size() != 1) {
        throw std::invalid_argument("Invalid expression");
    }

    return deque.back();
}
