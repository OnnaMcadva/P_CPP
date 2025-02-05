#include <iostream>
#include "whatever.hpp"

struct Point {
    int x, y;
};

bool operator<(const Point &a, const Point &b) {
    return (a.x < b.x) || (a.x == b.x && a.y < b.y);
}

bool operator>(const Point &a, const Point &b) {
    return (a.x > b.x) || (a.x == b.x && a.y > b.y);
}

int main() {
    int a = 2;
    int b = 3;

    std::cout << "\033[33ma = " << a << ", b = " << b << "\033[0m" << std::endl;

    ::swap(a, b);
    std::cout << "swap(a, b): a = " << a << ", b = " << b << std::endl;
    std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
    std::cout << "max(a, b) = " << ::max(a, b) << std::endl;

    std::string c = "chaine1";
    std::string d = "chaine2";

    std::cout << "\n\033[33mc = " << c << ", d = " << d << "\033[0m" << std::endl;

    ::swap(c, d);
    std::cout << "swap(c, d): c = " << c << ", d = " << d << std::endl;
    std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
    std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

    Point p1 = {1, 2};
    Point p2 = {3, 1};

    std::cout << "\n\033[33mp1 = (" << p1.x << ", " << p1.y << "), p2 = (" << p2.x << ", " << p2.y << ")\033[0m\n";

    ::swap(p1, p2);
    std::cout << "swap(p1, p2): p1 = (" << p1.x << ", " << p1.y << "), p2 = (" << p2.x << ", " << p2.y << ")\n";
    std::cout << "min(p1, p2) = (" << ::min(p1, p2).x << ", " << ::min(p1, p2).y << ")\n";
    std::cout << "max(p1, p2) = (" << ::max(p1, p2).x << ", " << ::max(p1, p2).y << ")\n";

    int x = 42, y = 84;
    int *px = &x;
    int *py = &y;

    std::cout << "\n\033[33mBefore swap:\033[0m px = " << px << ", py = " << py << std::endl;

    ::swap(px, py);
    std::cout << "After swap(px, py): px = " << px << ", py = " << py << std::endl;

    std::cout << "\033[33mComparing addresses:\033[0m" << std::endl;
    if (px < py)
        std::cout << "px (" << px << ") is less than py (" << py << ")" << std::endl;
    else if (px > py)
        std::cout << "px (" << px << ") is greater than py (" << py << ")" << std::endl;
    else
        std::cout << "px and py point to the same address (" << px << ")" << std::endl;

    std::cout << "min(px, py) = " << ::min(px, py) << std::endl;
    std::cout << "max(px, py) = " << ::max(px, py) << std::endl;

    return 0;
}

