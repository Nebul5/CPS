#include "../headers/shape.h"
using cps::Shape;
#include "../headers/circle.h"
using cps::Circle;

#include "../headers/rectangle.h"
using cps::Rectangle;

#include "../headers/vertical.h"
using cps::Vertical;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/shape-writer.h"
using cps::writePSfile;

#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::make_shared;
using std::shared_ptr;
#include <utility>
using std::make_pair;
using std::pair;
#include <vector>
using std::vector;

int main() {
  int rad = 100;
  vector<shared_ptr<Shape>> shapes = {};
  auto bound_box = make_pair(200, 200);
  auto circle_point = make_pair(0, 0);
  // auto test_circ = make_shared<Circle>(Circle(rad, bound_box, circle_point));
  // shapes.push_back(test_circ);
  auto polygon_point = make_pair(200, 200);
  auto test_polygon = make_shared<Polygon>(getPolygon(polygon_point, 5, 100));
  shapes.push_back(test_polygon);

  auto vertical_polygon_point = make_pair(400, 400);
  auto bottom_polygon =
      make_shared<Polygon>(getPolygon(vertical_polygon_point, 4, 100));
  auto top_polygon =
      make_shared<Polygon>(getPolygon(vertical_polygon_point, 6, 100));

  auto vertical =
      make_shared<Vertical>(Vertical({bottom_polygon, top_polygon}));
  shapes.push_back(vertical);
  writePSfile(shapes, "main");

  return 0;
}
