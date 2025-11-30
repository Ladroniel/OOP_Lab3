#pragma once
#include <iosfwd>

struct Point {
    double x{};
    double y{};
};

inline Point operator+(Point a, Point b) { return {a.x + b.x, a.y + b.y}; }
inline Point operator-(Point a, Point b) { return {a.x - b.x, a.y - b.y}; }
inline Point operator/(Point a, double k) { return {a.x / k, a.y / k}; }

std::ostream& operator<<(std::ostream& os, const Point& p);
std::istream& operator>>(std::istream& is, Point& p);
