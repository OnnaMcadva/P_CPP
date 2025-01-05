#include "Point.hpp"

// Default constructor
Point::Point() : _x(0), _y(0) {}

// Constructor with floating-point parameters
Point::Point(const float x, const float y) : _x(x), _y(y) {}

// Copy constructor
Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

// Copy assignment operator
Point& Point::operator=(const Point& other) {
    // As attributes are const, assignment is forbidden. This operator does nothing.
    (void)other; // Prevent unused variable warning.
    return *this;
}

// Destructor
Point::~Point() {}

// Getters
Fixed Point::getX() const {
    return _x;
}

Fixed Point::getY() const {
    return _y;
}

