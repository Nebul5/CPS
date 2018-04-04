#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/vertical.h"
using cps::Vertical;
#include "catch.hpp"

#include <fstream>
using std::fstream;
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
    double expected_height = 205.0;
    REQUIRE(vertical_polygon.getBoundBox().second >= expected_height);
    REQUIRE(vertical_polygon.getBoundBox().second <= expected_height + 1.0);

    fstream to_ps;
    to_ps.open("test-vertical.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    to_ps << vertical_polygon.toPostScript();
    to_ps.close();
  }
}
