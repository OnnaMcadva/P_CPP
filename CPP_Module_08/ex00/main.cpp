#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    std::vector<int> vec;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 5);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(vec, 20);
        std::cout << "Found value: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

/* test
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    std::cout << "Initial size: " << vec.size() << std::endl; // 0
    std::cout << "Initial capacity: " << vec.capacity() << std::endl; // 0 или небольшое число в зависимости от реализации

    vec.push_back(1);
    std::cout << "Size after adding one element: " << vec.size() << std::endl; // 1
    std::cout << "Capacity after adding one element: " << vec.capacity() << std::endl; // >= 1

    return 0;
}
*/
