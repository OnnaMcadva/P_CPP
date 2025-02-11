#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (std::isspace(ch)) {
            continue;
        }

        if (std::isdigit(ch)) {
            deque.push_back(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (deque.size() < 2) {
                throw std::runtime_error("🦋 Error: invalid expression");
            }
            performOperation(ch);
        } else {
            throw std::runtime_error("🦋 Error: invalid character in expression");
        }
    }

    if (deque.size() != 1) {
        throw std::runtime_error("🦋 Error: invalid expression");
    }

    return deque.back();
}

void RPN::performOperation(char op) {
    int b = deque.back();
    deque.pop_back();
    int a = deque.back();
    deque.pop_back();

    switch (op) {
        case '+':
            deque.push_back(a + b);
            break;
        case '-':
            deque.push_back(a - b);
            break;
        case '*':
            deque.push_back(a * b);
            break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("🦋 Error: division by zero");
            }
            deque.push_back(a / b);
            break;
        default:
            throw std::runtime_error("🦋 Error: unknown operation");
    }
}
