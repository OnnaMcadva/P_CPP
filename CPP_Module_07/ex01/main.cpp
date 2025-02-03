#include <iostream>
#include "iter.hpp"
#include <cctype>

template <typename T>
void printElement(T &element) {
    std::cout << element << " ";
}

template <typename T>
void incrementElement(T &element) {
    element += 1;
}

void toUpper(std::string &str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(str[i]);
    }
}

int main(void) {

    int intArray[] = {1, 2, 3, 4, 5};
    size_t intArrayLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "Original int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    iter(intArray, intArrayLength, incrementElement<int>);

    std::cout << "Incremented int array: ";
    iter(intArray, intArrayLength, printElement<int>);
    std::cout << std::endl;

    std::string strArray[] = {"Hello", "World", "C++", "Templates"};
    size_t strArrayLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "Original string array: ";
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    iter(strArray, strArrayLength, toUpper);

    std::cout << "Uppercased string array: ";
    iter(strArray, strArrayLength, printElement<std::string>);
    std::cout << std::endl;

    return 0;
}