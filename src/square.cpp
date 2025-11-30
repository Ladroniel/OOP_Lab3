#include "square.hpp"
#include <iostream>
#include <cmath>
#include <stdexcept>

static double cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
static double dist2(Point a, Point b){ double dx=a.x-b.x, dy=a.y-b.y; return dx*dx+dy*dy; }

Square::Square(const Point& a, const Point& b) {
    v[0]=a; v[1]=b;
    double dx=b.x-a.x, dy=b.y-a.y;
    v[2] = {b.x - dy, b.y + dx};
    v[3] = {a.x - dy, a.y + dx};
    ensure_square();
}

void Square::ensure_square() {
    double d01 = dist2(v[0],v[1]);
    double d12 = dist2(v[1],v[2]);
    if (std::abs(d01 - d12) > 1e-6) {
        double side = std::sqrt(std::min(d01,d12));
        Point c = center();
        v[0] = {c.x - side/2, c.y - side/2};
        v[1] = {c.x + side/2, c.y - side/2};
        v[2] = {c.x + side/2, c.y + side/2};
        v[3] = {c.x - side/2, c.y + side/2};
    }
}

Point Square::center() const {
    Point s{};
    for (auto& p : v) s = s + p;
    return s/4.0;
}

double Square::area() const {
    double S = 0;
    for (int i=0;i<4;i++) {
        int j=(i+1)&3;
        S += cross(v[i], v[j]);
    }
    return std::abs(S)*0.5;
}

void Square::print(std::ostream& os) const {
    os << "Квадрат: ";
    for (int i=0;i<4;i++) {
        os << "("<<v[i].x<<","<<v[i].y<<")";
        if (i!=3) os << " ";
    }
}

void Square::read(std::istream& is) {
    for (int i=0;i<2;i++) is >> v[i].x >> v[i].y;
    double dx=v[1].x-v[0].x, dy=v[1].y-v[0].y;
    v[2] = {v[1].x - dy, v[1].y + dx};
    v[3] = {v[0].x - dy, v[0].y + dx};
    ensure_square();
}
