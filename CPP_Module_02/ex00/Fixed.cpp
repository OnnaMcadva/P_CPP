#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "\033[32mDefault constructor called\033[0m" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "\033[33mCopy constructor called\033[0m" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "\033[34mCopy assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "\033[31mDestructor called\033[0m" << std::endl;
}

int Fixed::getRawBits() const {
    std::cout << "\033[35mgetRawBits member function called\033[0m" << std::endl;
    return this->_value;
}

void Fixed::setRawBits(int const raw) {
    std::cout << "\033[36msetRawBits member function called\033[0m" << std::endl;
    this->_value = raw;
}
