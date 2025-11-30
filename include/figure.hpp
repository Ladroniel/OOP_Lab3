#pragma once
#include "point.hpp"
#include <iosfwd>
#include <cmath>

class Figure {
public:
    virtual ~Figure() = default;

    virtual Point center() const = 0;
    virtual double area() const = 0;
    virtual void print(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;

    explicit operator double() const { return area(); }

    bool operator==(const Figure& other) const {
        const double eps = 1e-9;
        return std::abs(area() - other.area()) < eps;
    }
};

inline std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.print(os);
    return os;
}

inline std::istream& operator>>(std::istream& is, Figure& f) {
    f.read(is);
    return is;
}
