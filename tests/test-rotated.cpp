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
using std::ofstream;
#include <utility>
using std::make_pair;
using std::pair;
#include <memory>
using std::make_shared;
using std::shared_ptr;

TEST_CASE("testing rotated shape class") {
  SECTION("testing with Polygon and writing to postscript") {
    pair<int, int> center_point = make_pair(100, 100);
    auto test_polygon = make_shared<Polygon>(getPolygon(center_point, 5, 100));
    auto original_ps_str = test_polygon->toPostScript();
    auto rotated_polygon =
        Rotated(make_shared<Polygon>(Polygon(*test_polygon)), 90);

    REQUIRE(test_polygon->getStartingPoint() !=
            (rotated_polygon.getShape())->getStartingPoint());
    REQUIRE(test_polygon->getBoundBox() != rotated_polygon.getBoundBox());
    REQUIRE(test_polygon->getCurrentPoint() ==
            rotated_polygon.getCurrentPoint());

    ofstream to_ps;
    to_ps.open("test-rotated.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    auto to_ps_str = original_ps_str + "\n" + rotated_polygon.toPostScript();
    to_ps << to_ps_str;
    to_ps.close();
  }
}
