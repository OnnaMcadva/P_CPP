#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

int main() {
    Point a(0, 0);
    Point b(10, 0);
    Point c(0, 10);

    Point p1(2, 2);    // Внутри треугольника
    Point p2(5, 5);    // Вне треугольника
    Point p3(10, 0);   // На стороне треугольника

    std::cout << "p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle\n";
    std::cout << "p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle\n";
    std::cout << "p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle\n";

    return 0;
}
