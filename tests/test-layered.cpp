#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/layered.h"
using cps::Layered;
#include "catch.hpp"

#include <fstream>
using std::ofstream;
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <utility>
using std::make_pair;
using std::pair;

TEST_CASE(" testing layered shape") {
  SECTION(" testing constructors ") {
    auto layered_point = make_pair(400, 450);
    auto dummy_current_point = make_pair(0, 0);
    auto polygon_bottom =
        make_shared<Polygon>(getPolygon(layered_point, 4, 100));
    auto polygon_top =
        make_shared<Polygon>(getPolygon(dummy_current_point, 5, 150));
    cout << "polygon bottom width is " << polygon_bottom->getBoundBox().first
         << endl;
    auto layered_polygon = Layered({polygon_bottom, polygon_top});
    double expected_height = 230.0;
    REQUIRE(layered_polygon.getBoundBox().second >= expected_height);
    REQUIRE(layered_polygon.getBoundBox().second <= expected_height + 1.0);

    ofstream to_ps;
    to_ps.open("test-layered.ps");
    if (not to_ps.is_open()) {
      cout << "could not open file" << endl;
    }
    auto to_ps_str = layered_polygon.toPostScript();
    to_ps << to_ps_str;
    to_ps.close();
  }
}
