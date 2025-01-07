#include "Fixed.hpp"
#include "Point.hpp"
#include "bsp.hpp"
#include <iostream>

/*
    The name of members should not start with underscore as that is reserved bz the C++ language. 
    Some other nitpicks or opinions include not using this pointer to access members inside methods
    and that some comparison operator may be defined using other comp. ops.
*/

int main() {
    Point a(10, 0);
    Point b(0, 0);
    Point c(0, 10);

    if (!isValidTriangle(a, b, c)) {
    std::cerr << "\033[31mError:\033[0m The points do not form a valid triangle!" << std::endl;
    return 1;
    }

    Point p1(2, 2);    // Внутри треугольника
    Point p2(5, 5);    // Вне треугольника
    Point p3(10, 0);   // На стороне треугольника

    std::cout << "p1 is " << (bsp(a, b, c, p1) ? "inside" : "outside") << " the triangle\n";
    std::cout << "p2 is " << (bsp(a, b, c, p2) ? "inside" : "outside") << " the triangle\n";
    std::cout << "p3 is " << (bsp(a, b, c, p3) ? "inside" : "outside") << " the triangle\n";

    return 0;
}
