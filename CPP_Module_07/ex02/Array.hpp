#pragma once
#include <cstddef>
#include <exception>

template <typename T>
class Array {
private:
    T* array;
    size_t arraySize;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    size_t size() const;

    class OutOfBoundsException : public std::exception {
    public:
        const char* what() const throw() {
            return "Index out of bounds";
        }
    };
};

#include "Array.tpp"

