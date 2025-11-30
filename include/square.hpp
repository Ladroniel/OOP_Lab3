#pragma once
#include "figure.hpp"

class Square final : public Figure {
public:
    Square() = default;
    Square(const Point& a, const Point& b);

    Point center() const override;
    double area() const override;
    void print(std::ostream& os) const override;
    void read(std::istream& is) override;

private:
    Point v[4]{};
    void ensure_square();
};
