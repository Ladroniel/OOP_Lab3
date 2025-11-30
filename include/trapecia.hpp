#pragma once
#include "figure.hpp"

class Trapezoid final : public Figure {
public:
    Trapezoid() = default;

    Trapezoid(const Point& a,
              const Point& b,
              const Point& c,
              const Point& d);

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    Point v[4]{};
};
