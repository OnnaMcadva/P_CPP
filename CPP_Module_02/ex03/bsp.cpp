#include "bsp.hpp"
#include "Fixed.hpp"
#include "Point.hpp"

static Fixed sign(Point const p1, Point const p2, Point const p3) {
    return (p1.getX() - p3.getX()) * (p2.getY() - p3.getY()) - 
           (p2.getX() - p3.getX()) * (p1.getY() - p3.getY());
}

bool isValidTriangle(Point const& a, Point const& b, Point const& c) {
    Fixed area = sign(a, b, c);
    return area != 0;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
    if (!isValidTriangle(a, b, c)) {
        return false;
    }

    Fixed d1 = sign(point, a, b);
    Fixed d2 = sign(point, b, c);
    Fixed d3 = sign(point, c, a);

    if (d1 == 0 || d2 == 0 || d3 == 0) {
        return false;
    }

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}
