#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "catch.hpp"

#include <utility>
using std::make_pair;
using std::pair;

#include <iostream>
using std::cout;
using std::endl;

TEST_CASE("test polygon shape") {
  SECTION("constructors behave") {
    pair<unsigned int, unsigned int> bound_box = make_pair(10, 12);
    pair<unsigned int, unsigned int> current_point = make_pair(0, 0);
    unsigned int number_sides = 4;
    unsigned int side_length = 10;

    auto test_polygon =
        Polygon(bound_box, current_point, number_sides, side_length);

    REQUIRE(test_polygon.getSideLength() == side_length);
    REQUIRE(test_polygon.getNumberOfSides() == number_sides);
    REQUIRE(test_polygon.getBoundBox() == bound_box);
    REQUIRE(test_polygon.getCurrentPoint() == current_point);
    cout << " getting polygon post script " << endl;
    cout << test_polygon.toPostScript() << endl;
  }
  SECTION("getPolygon function behaves") {
    pair<unsigned int, unsigned int> current_point = make_pair(0, 0);
    unsigned int number_sides = 5;
    unsigned int side_length = 10;
    auto calculated_polygon =
        getPolygon(current_point, number_sides, side_length);
    auto bound_box = calculated_polygon.getBoundBox();
    cout << "bound box width is " << bound_box.first << " and height is "
         << bound_box.second << endl;
  }
}
