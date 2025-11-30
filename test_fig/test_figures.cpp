#include <gtest/gtest.h>
#include "square.hpp"
#include "rectangle.hpp"
#include "trapecia.hpp"

TEST(SquareTest, AreaCenter) {
    Square s({0,0},{1,0});
    EXPECT_NEAR((double)s, 1.0, 1e-6);
    auto c = s.center();
    EXPECT_NEAR(c.x, 0.5, 1e-6);
    EXPECT_NEAR(c.y, 0.5, 1e-6);
}

TEST(RectangleTest, Area) {
    Rectangle r({0,0},{3,0},{3,2},{0,2});
    EXPECT_NEAR(r.area(), 6.0, 1e-9);
}

TEST(TrapezoidTest, Area) {
    Trapezoid t({0,0},{4,0},{3,2},{1,2});
    EXPECT_NEAR(t.area(), 6.0, 1e-9);
}
