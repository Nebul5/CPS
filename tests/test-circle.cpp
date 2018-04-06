#include <iostream>
using std::cout;
using std::endl;
#include "../headers/shape.h"
using cps::Shape;
#include "../headers/circle.h"
using cps::Circle;
#include "catch.hpp"

#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE("test circle shape") {
  SECTION("constructors behave") {
    int radius = 5;
    pair<double, double> bound_box = make_pair(10, 10);
    pair<int, int> current_point = make_pair(0, 0);

    auto test_circle = Circle(radius, bound_box, current_point);

    REQUIRE(test_circle.getRadius() == radius);
    REQUIRE(test_circle.getBoundBox() == bound_box);
    REQUIRE(test_circle.getCurrentPoint() == current_point);
    cout << "getting circle post script" << endl;
    cout << test_circle.toPostScript() << endl;
  }
}
