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
    pair<float, float> bound_box = make_pair(10, 12);
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

    // These Conditions Match those used for the drawing in test_rect.ps and
    // test_poly.ps
    unsigned int n1 = 3;  // smallest case
    unsigned int n2 = 7;  // odd case
    unsigned int n3 = 8;  // mod 4 ==0 case
    unsigned int n4 = 10; // mod 2 but not mod 4 case
    unsigned int side = 100;
    current_point = make_pair(300, 300);

    auto triangle = getPolygon(current_point, n1, side);
    auto septagon = getPolygon(current_point, n2, side);
    auto octagon = getPolygon(current_point, n3, side);
    auto decagon = getPolygon(current_point, n4, side);

    // Test the Bounding Boxes
    auto tbox = triangle.getBoundBox();
    REQUIRE(tbox.first == 115.47005f);
    REQUIRE(tbox.second == 86.60254f);

    auto sbox = septagon.getBoundBox();
    REQUIRE(sbox.first == 224.69795f);
    REQUIRE(sbox.second == 219.06432f);

    auto obox = octagon.getBoundBox();
    REQUIRE(obox.first == 241.42136f);
    REQUIRE(obox.second == 241.42136f);

    auto dbox = decagon.getBoundBox();
    REQUIRE(dbox.first == 323.60678f);
    REQUIRE(dbox.second == 307.76834f);

    // test the Starting Points this is the left end of the bottom side of the
    // polygon (where the postscript drawing begins)
    // auto tstart = triangle.getStartingPoint(current_point, n1, side);
    REQUIRE(triangle.getStartingPoint().first == 250);
    REQUIRE(triangle.getStartingPoint().second == 256);

    // auto sstart = septagon.getStartingPoint(current_point, n2, side);
    REQUIRE(septagon.getStartingPoint().first == 250);
    REQUIRE(septagon.getStartingPoint().second == 191);

    // auto ostart = octagon.getStartingPoint(current_point, n3, side);
    REQUIRE(octagon.getStartingPoint().first == 250);
    REQUIRE(octagon.getStartingPoint().second == 179);

    // auto dstart = decagon.getStartingPoint(current_point, n4, side);
    REQUIRE(decagon.getStartingPoint().first == 250);
    REQUIRE(decagon.getStartingPoint().second == 146);
  }
}
