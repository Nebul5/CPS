#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/rotated.h"
using cps::Rotated;
#include "catch.hpp"

#include <iostream>
using std::cout;
using std::endl;
#include <fstream>
using std::fstream;
#include <utility>
using std::make_pair;
using std::pair;
#include <memory>
using std::make_shared;
using std::shared_ptr;

TEST_CASE("testing rotated shape class") {
  SECTION("testing with Polygon") {
    pair<int, int> center_point = make_pair(100, 100);
    auto test_polygon = make_shared<Polygon>(getPolygon(center_point, 5, 100));
    auto original_ps_str = test_polygon->toPostScript();
    auto original_starting_point = test_polygon->getStartingPoint();
    auto rotated_polygon = Rotated(test_polygon, 90);
    auto rotated_starting_point = test_polygon->getStartingPoint();
    // REQUIRE(original_starting_point != rotated_starting_point);
    fstream to_ps;
    to_ps.open("test-rotated.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    auto to_ps_str = original_ps_str + "\n" + rotated_polygon.toPostScript();
    to_ps << to_ps_str;
    to_ps.close();
  }
}
