#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "\033[32mDefault constructor called\033[0m" << std::endl;
}

// Fixed::Fixed(const int intValue) {
//     std::cout << "Int constructor called" << std::endl;
//     _value = intValue << _fractionalBits;
// }

Fixed::Fixed(const int intValue) {
    std::cout <<  "Int constructor called. \033[36mConverting " << intValue
              << " to fixed-point. Result: " << (intValue << _fractionalBits)
              << "\033[0m" << std::endl;
    _value = intValue << _fractionalBits;
}

// Fixed::Fixed(const float floatValue) {
//     std::cout << "Float constructor called" << std::endl;
//     _value = roundf(floatValue * (1 << _fractionalBits));
// }

Fixed::Fixed(const float floatValue) {
    std::cout << "Float constructor called. \033[35mConverting " << floatValue
              << " to fixed-point. Result: " << roundf(floatValue * (1 << _fractionalBits))
              << "\033[0m" << std::endl;
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "\033[33mCopy constructor called\033[0m" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "\033[34mCopy assignment operator called\033[0m" << std::endl;
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {
    std::cout << "\033[31mDestructor called\033[0m" << std::endl;
}

int Fixed::getRawBits() const {
    return _value;
}

void Fixed::setRawBits(int const raw) {
    _value = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(_value) / (1 << _fractionalBits);
}

int Fixed::toInt() const {
    return _value >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
