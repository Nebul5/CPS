#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/scaled.h"
using cps::Scaled;
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE(" testing scaled shape") {
  SECTION(" testing constructor ") {
    auto current_point = make_pair(0, 0);
    auto number_sides = 5;
    auto side_length = 100;
    auto test_polygon = getPolygon(current_point, number_sides, side_length);

    auto scale = make_pair(2.0, 3.0);
    Scaled<Polygon> scaled_polygon(test_polygon, scale);
    REQUIRE(scaled_polygon.getShape() == test_polygon);
    cout << "get scaled ps_polygon" << endl;
    cout << scaled_polygon.toPostScript() << endl;
  }
}
