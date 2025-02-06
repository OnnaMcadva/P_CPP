#include <iostream>
#include "Span.hpp"

int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "✨ Shortest span: " << sp.shortestSpan() << std::endl;
    std::cout << "💎 Longest span: " << sp.longestSpan() << std::endl;

    Span bigSpan(10000);
    std::vector<int> numbers;
    for (int i = 0; i < 10000; ++i) {
        numbers.push_back(i * 2);
    }
    bigSpan.addNumber(numbers.begin(), numbers.end());

    std::cout << "✨ Shortest span in bigSpan: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "💎 Longest span in bigSpan: " << bigSpan.longestSpan() << std::endl;

    return 0;
}

