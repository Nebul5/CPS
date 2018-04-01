#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/vertical.h"
using cps::Vertical;
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE(" testing vertical shape") {
  SECTION(" testing constructors ") {
    auto bottom_current_point = make_pair(30, 55);
    auto dummy_current_point = make_pair(0, 0);
    auto polygon_bottom = getPolygon(bottom_current_point, 4, 100);
    auto polygon_top = getPolygon(dummy_current_point, 4, 100);
    cout << "polygon bottom width is " << polygon_bottom.getBoundBox().first
         << endl;
    auto vertical_polygon = Vertical({polygon_bottom, polygon_top});
    auto expected_height = 205;
    REQUIRE(vertical_polygon.getBoundBox().second == expected_height);
  }
}
