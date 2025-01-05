
/*
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}
*/


#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << "Initial values:" << std::endl;
    std::cout << "a: " << a.getRawBits() << std::endl;
    std::cout << "b: " << b.getRawBits() << std::endl;
    std::cout << "c: " << c.getRawBits() << std::endl;

    a.setRawBits(42);
    std::cout << "After setting a to 42:" << std::endl;
    std::cout << "a: " << a.getRawBits() << std::endl;

    c.setRawBits(-12345);
    std::cout << "After setting c to -12345:" << std::endl;
    std::cout << "c: " << c.getRawBits() << std::endl;

    return 0;
}
