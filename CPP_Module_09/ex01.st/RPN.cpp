#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& other) : stack(other.stack) {}
RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        stack = other.stack;
    }
    return *this;
}
RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (std::isspace(ch)) {
            continue;
        }

        if (std::isdigit(ch)) {
            stack.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            if (stack.size() < 2) {
                throw std::runtime_error("🦋 Error: invalid expression");
            }
            performOperation(ch);
        } else {
            throw std::runtime_error("🦋 Error: invalid character in expression");
        }
    }

    if (stack.size() != 1) {
        throw std::runtime_error("🦋 Error: invalid expression");
    }

    return stack.top();
}

void RPN::performOperation(char op) {
    int b = stack.top();
    stack.pop();
    int a = stack.top();
    stack.pop();

    switch (op) {
        case '+':
            stack.push(a + b);
            break;
        case '-':
            stack.push(a - b);
            break;
        case '*':
            stack.push(a * b);
            break;
        case '/':
            if (b == 0) {
                throw std::runtime_error("🦋 Error: division by zero");
            }
            stack.push(a / b);
            break;
        default:
            throw std::runtime_error("🦋 Error: unknown operation");
    }
}
