#include "Fixed.hpp"
#include <iostream>

int main() {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << "a: " << a << std::endl;
    std::cout << "++a: " << ++a << std::endl;
    std::cout << "a: " << a << std::endl;
    std::cout << "a++: " << a++ << std::endl;
    std::cout << "a: " << a << std::endl;

    std::cout << "b: " << b << std::endl;

    std::cout << "\033[35mmax(a, b): " << Fixed::max(a, b) << "\033[0m" << std::endl;
    std::cout << "\033[36mmin(a, b): " << Fixed::min(a, b) << "\033[0m" << std::endl;

    Fixed c(10);
    Fixed d(0);

    try {
        std::cout << "c / d: " << (c / d) << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

        std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;

    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "b > a: " << (b > a) << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;

    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "b < a: " << (b < a) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;

    std::cout << "a >= b: " << (a >= b) << std::endl;
    std::cout << "b >= a: " << (b >= a) << std::endl;
    std::cout << "b >= c: " << (b >= c) << std::endl;

    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "b <= a: " << (b <= a) << std::endl;
    std::cout << "b <= c: " << (b <= c) << std::endl;

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "b == c: " << (b == c) << std::endl;

    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a != c: " << (a != c) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;

    return 0;
}
