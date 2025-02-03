#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : array(NULL), arraySize(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arraySize(n) {
    array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other) : array(NULL), arraySize(0) {
    *this = other;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        delete[] array;
        arraySize = other.arraySize;
        array = new T[arraySize];
        for (size_t i = 0; i < arraySize; ++i) {
            array[i] = other.array[i];
        }
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] array;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= arraySize) {
        throw OutOfBoundsException();
    }
    return array[index];
}

template <typename T>
const T& Array<T>::operator[](size_t index) const {
    if (index >= arraySize) {
        throw OutOfBoundsException();
    }
    return array[index];
}

template <typename T>
size_t Array<T>::size() const {
    return arraySize;
}
