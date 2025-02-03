#include <limits>
#include "Span.hpp"

Span::Span(unsigned int n) : maxSize(n) {}

Span::Span(const Span& other) : numbers(other.numbers), maxSize(other.maxSize) {}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        numbers = other.numbers;
        maxSize = other.maxSize;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int number) {
    if (numbers.size() >= maxSize) {
        throw SpanFullException();
    }
    numbers.push_back(number);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) > static_cast<int>(maxSize - numbers.size())) {
        throw SpanFullException();
    }
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw NotEnoughElementsException();
    }
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());
    int minSpan = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        minSpan = std::min(minSpan, sortedNumbers[i] - sortedNumbers[i - 1]);
    }
    return minSpan;
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw NotEnoughElementsException();
    }
    int minElement = *std::min_element(numbers.begin(), numbers.end());
    int maxElement = *std::max_element(numbers.begin(), numbers.end());
    return maxElement - minElement;
}
