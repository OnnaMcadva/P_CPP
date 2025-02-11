#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

int RPN::evaluate(const std::string &expression) {
    for (size_t i = 0; i < expression.size(); ++i) {
        char ch = expression[i];

        if (std::isspace(ch)) {
            continue; // Пропускаем пробелы
        }

        if (std::isdigit(ch)) {
            stack.push(ch - '0'); // Преобразуем символ в число и добавляем в стек
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

    return stack.top(); // Возвращаем результат
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
