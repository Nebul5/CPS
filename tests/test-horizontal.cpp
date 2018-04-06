#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/horizontal.h"
using cps::Horizontal;
#include "catch.hpp"

#include <fstream>
using std::fstream;
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE("testing horizontal shape") {
  SECTION("testing constructors") {
    auto leftmost_current_point = make_pair(200, 200);
    auto dummy_current_point = make_pair(0, 0);

    auto left_polygon =
        make_shared<Polygon>(getPolygon(leftmost_current_point, 4, 100));

    auto right_polygon =
        make_shared<Polygon>(getPolygon(dummy_current_point, 4, 100));

    auto horizontal_polygon = Horizontal({left_polygon, right_polygon});
    double expected_width = 350.0;
    REQUIRE(horizontal_polygon.getBoundBox().first >= expected_width);
    REQUIRE(horizontal_polygon.getBoundBox().first <= expected_width + 1);

    fstream to_ps;
    to_ps.open("test-horizontal.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    auto to_ps_str = horizontal_polygon.toPostScript();
    to_ps << to_ps_str;
    to_ps.close();
  }
}
