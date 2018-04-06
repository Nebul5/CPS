#include <iostream>
using std::cout;
using std::endl;
#include "../headers/shape.h"
using cps::Shape;
#include "../headers/circle.h"
using cps::Circle;
using cps::getCircle;
#include "catch.hpp"

#include <fstream>
using std::ofstream;
#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE("test circle shape") {
  pair<int, int> current_point = make_pair(0, 0);
  SECTION("constructors behave") {
    auto radius = 5;
    pair<double, double> bound_box = make_pair(10, 10);

    auto test_circle = Circle(radius, bound_box, current_point);

    REQUIRE(test_circle.getRadius() == radius);
    REQUIRE(test_circle.getBoundBox() == bound_box);
    REQUIRE(test_circle.getCurrentPoint() == current_point);
  }
  SECTION("writing postscript file") {
    auto radius = 100;
    auto test_circle = getCircle(current_point, radius);
    cout << test_circle.toPostScript() << endl;
    ofstream to_ps;
    to_ps.open("test-circle.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    auto to_ps_str = test_circle.toPostScript();
    to_ps << to_ps_str;
    to_ps.close();
  }
}
