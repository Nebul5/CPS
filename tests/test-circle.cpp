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
    auto radius = 5;
    auto bound_box = make_pair(10, 10);
    auto current_point = make_pair(0, 0);

    auto test_circ = Circle(radius, bound_box, current_point);

    REQUIRE(test_circ.getRadius() == radius);
    REQUIRE(test_circ.getBoundBox() == bound_box);
    REQUIRE(test_circ.getCurrentPoint() == current_point);
  }
}
