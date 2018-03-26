#include "../headers/shape.h"
using cps::Shape;
#include "../headers/rectangle.h"
using cps::Rectangle;
#include "catch.hpp"

#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE("test rectangle shape") {
  SECTION("constructors behave") {
    auto bound_box = make_pair(10, 12);
    auto current_point = make_pair(0, 0);

    auto test_rectangle = Rectangle(bound_box, current_point);

    REQUIRE(test_rectangle.getWidth() == bound_box.first);
    REQUIRE(test_rectangle.getHeight() == bound_box.second);
    REQUIRE(test_rectangle.getBoundBox() == bound_box);
    REQUIRE(test_rectangle.getCurrentPoint() == current_point);
  }
}
