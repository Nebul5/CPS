#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "catch.hpp"

#include <cmath>
using std::abs;

#include <utility>
using std::make_pair;
using std::pair;
#include <fstream>
using std::fstream;
#include <iostream>
using std::cout;
using std::endl;

bool within_one(double val1, double val2) { return abs(val1 - val2) <= 1.0; }
bool within_one(int val1, int val2) { return abs(val1 - val2) <= 1; }
TEST_CASE("test polygon shape") {
  SECTION("constructors behave") {
    pair<double, double> bound_box = make_pair(10, 12);
    pair<int, int> current_point = make_pair(15, 15);
    int number_sides = 4;
    int side_length = 10;

    auto test_polygon =
        Polygon(bound_box, current_point, number_sides, side_length);

    REQUIRE(test_polygon.getSideLength() == side_length);
    REQUIRE(test_polygon.getNumberOfSides() == number_sides);
    REQUIRE(test_polygon.getBoundBox() == bound_box);
    REQUIRE(test_polygon.getCurrentPoint() == current_point);
    cout << " getting polygon post script " << endl;
    cout << test_polygon.toPostScript() << endl;
    fstream to_ps;
    to_ps.open("test-polygon.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    to_ps << test_polygon.toPostScript();
    to_ps.close();
  }
  SECTION("getPolygon function behaves") {
    pair<int, int> current_point = make_pair(0, 0);
    int number_sides = 5;
    int side_length = 10;
    auto calculated_polygon =
        getPolygon(current_point, number_sides, side_length);
    auto bound_box = calculated_polygon.getBoundBox();
    cout << "bound box width is " << bound_box.first << " and height is "
         << bound_box.second << endl;

    // These Conditions Match those used for the drawing in test_rect.ps and
    // test_poly.ps
    int n1 = 3;  // smallest case
    int n2 = 7;  // odd case
    int n3 = 8;  // mod 4 ==0 case
    int n4 = 10; // mod 2 but not mod 4 case
    int side = 100;
    current_point = make_pair(300, 300);

    auto triangle = getPolygon(current_point, n1, side);
    auto septagon = getPolygon(current_point, n2, side);
    auto octagon = getPolygon(current_point, n3, side);
    auto decagon = getPolygon(current_point, n4, side);

    // Test the Bounding Boxes
    auto tbox = triangle.getBoundBox();
    REQUIRE(within_one(tbox.first, 115.5));
    REQUIRE(within_one(tbox.second, 86.6));

    auto sbox = septagon.getBoundBox();
    REQUIRE(within_one(sbox.first, 230.476));
    REQUIRE(within_one(sbox.second, 219.0));

    auto obox = octagon.getBoundBox();
    REQUIRE(within_one(obox.first, 241.4));
    REQUIRE(within_one(obox.second, 241.4));

    auto dbox = decagon.getBoundBox();
    REQUIRE(within_one(dbox.first, 323.6));
    REQUIRE(within_one(dbox.second, 307.7));

    // test the Starting Points this is the left end of the bottom side of the
    // polygon (where the postscript drawing begins)
    // auto tstart = triangle.getStartingPoint(current_point, n1, side);
    REQUIRE(triangle.getStartingPoint().first == 250);
    REQUIRE(triangle.getStartingPoint().second == 271);

    // auto sstart = septagon.getStartingPoint(current_point, n2, side);
    REQUIRE(septagon.getStartingPoint().first == 250);
    REQUIRE(septagon.getStartingPoint().second == 196);

    // auto ostart = octagon.getStartingPoint(current_point, n3, side);
    REQUIRE(octagon.getStartingPoint().first == 250);
    REQUIRE(octagon.getStartingPoint().second == 179);

    // auto dstart = decagon.getStartingPoint(current_point, n4, side);
    REQUIRE(decagon.getStartingPoint().first == 250);
    REQUIRE(decagon.getStartingPoint().second == 146);
  }
}
