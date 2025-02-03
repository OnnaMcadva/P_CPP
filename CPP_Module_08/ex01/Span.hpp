#pragma once
#include <vector>
#include <algorithm>
#include <iterator>
#include <stdexcept>

class Span {
private:
    std::vector<int> numbers;
    unsigned int maxSize;

public:
    Span(unsigned int n);
    Span(const Span& other);
    Span& operator=(const Span& other);
    ~Span();

    void addNumber(int number);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan() const;
    int longestSpan() const;

    class SpanFullException : public std::exception {
    public:
        const char* what() const throw() {
            return "Span is already full";
        }
    };

    class NotEnoughElementsException : public std::exception {
    public:
        const char* what() const throw() {
            return "Not enough elements to calculate span";
        }
    };
};
