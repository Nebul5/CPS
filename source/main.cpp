#include "../headers/shape.h"
using cps::Shape;
#include "../headers/circle.h"
using cps::Circle;
using cps::getCircle;
#include "../headers/rectangle.h"
using cps::Rectangle;
#include "../headers/polygon.h"
using cps::getPolygon;
using cps::Polygon;
#include "../headers/vertical.h"
using cps::Vertical;
#include "../headers/horizontal.h"
using cps::Horizontal;
#include "../headers/scaled.h"
using cps::Scaled;
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
  int radius = 100;
  vector<shared_ptr<Shape>> shapes = {};
  auto circle_point = make_pair(200, 500);
  auto test_circ = make_shared<Circle>(getCircle(circle_point, radius));
  shapes.push_back(test_circ);

  auto polygon_point = make_pair(100, 100);
  auto test_polygon = make_shared<Polygon>(getPolygon(polygon_point, 3, 80));
  shapes.push_back(test_polygon);

  auto vertical_polygon_point = make_pair(450, 400);
  auto bottom_polygon =
      make_shared<Polygon>(getPolygon(vertical_polygon_point, 4, 100));
  auto top_polygon =
      make_shared<Polygon>(getPolygon(vertical_polygon_point, 6, 100));

  auto vertical =
      make_shared<Vertical>(Vertical({bottom_polygon, top_polygon}));

  shapes.push_back(vertical);
  auto scaled_point = make_pair(200, 200);
  auto polygon_to_scale =
      make_shared<Polygon>(getPolygon(scaled_point, 5, 100));
  auto scale = make_pair<double, double>(2.0, 2.0);
  auto scaled = make_shared<Scaled>(
      Scaled(make_shared<Polygon>(Polygon(*polygon_to_scale)), scale));
  shapes.push_back(polygon_to_scale);
  shapes.push_back(scaled);

  /*
    auto horizontal_polygon_point = make_pair(200, 300);
    auto left_polygon =
        make_shared<Polygon>(getPolygon(horizontal_polygon_point, 5, 100));
    auto right_polygon =
        make_shared<Polygon>(getPolygon(horizontal_polygon_point, 4, 100));

    auto horizontal =
        make_shared<Horizontal>(Horizontal({left_polygon, right_polygon}));
    shapes.push_back(horizontal);
  */

  writePSfile(shapes, "main3");

  return 0;
}
