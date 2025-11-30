#include "trapecia.hpp"
#include <iostream>
#include <cmath>

static double cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}

Trapezoid::Trapezoid(const Point& a,
                     const Point& b,
                     const Point& c,
                     const Point& d)
{
    v[0] = a;
    v[1] = b;
    v[2] = c;
    v[3] = d;
}

Point Trapezoid::center() const {
    Point s{};
    for (auto& p : v) s = s + p;
    return s / 4.0;
}

double Trapezoid::area() const {
    double S = 0;
    for (int i = 0; i < 4; i++) {
        int j = (i + 1) & 3;
        S += cross(v[i], v[j]);
    }
    return std::abs(S) * 0.5;
}

void Trapezoid::print(std::ostream& os) const {
    os << "Трапеция: ";
    for (int i = 0; i < 4; i++) {
        os << "(" << v[i].x << "," << v[i].y << ")";
        if (i != 3) os << " ";
    }
}

void Trapezoid::read(std::istream& is) {
    for (int i = 0; i < 4; i++)
        is >> v[i].x >> v[i].y;
}
