#include "Fixed.hpp"

// Constructors / Destructor
Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int intValue) {
    _value = intValue << _fractionalBits;
}

Fixed::Fixed(const float floatValue) {
    _value = roundf(floatValue * (1 << _fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        _value = other._value;
    }
    return *this;
}

Fixed::~Fixed() {}

// Getters / Setters
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

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return _value > other._value;
}

bool Fixed::operator<(const Fixed& other) const {
    return _value < other._value;
}

bool Fixed::operator>=(const Fixed& other) const {
    return _value >= other._value;
}

bool Fixed::operator<=(const Fixed& other) const {
    return _value <= other._value;
}

bool Fixed::operator==(const Fixed& other) const {
    return _value == other._value;
}

bool Fixed::operator!=(const Fixed& other) const {
    return _value != other._value;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other._value == 0) {
        throw std::runtime_error("\033[31mDivision by zero\033[0m");
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Fixed Fixed::operator/(const Fixed& other) const {
//     if (other._value == 0) {
//         throw std::runtime_error("Division by zero");
//     }
//     Fixed result;
//     result.setRawBits((_value << _fractionalBits) / other._value);
//     return result;
// }


// Increment / Decrement operators
Fixed& Fixed::operator++() { // Pre-increment
    _value++;
    return *this;
}

Fixed Fixed::operator++(int) { // Post-increment
    Fixed temp(*this);
    _value++;
    return temp;
}

Fixed& Fixed::operator--() { // Pre-decrement
    _value--;
    return *this;
}

Fixed Fixed::operator--(int) { // Post-decrement
    Fixed temp(*this);
    _value--;
    return temp;
}

// Static member functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Overload for output stream
std::ostream& operator<<(std::ostream& out, const Fixed& value) {
    out << value.toFloat();
    return out;
}
