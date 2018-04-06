#include "../headers/shape.h"
using cps::Shape;
#include "../headers/circle.h"
using cps::Circle;
#include "../headers/consts.h"
using cps::DRAW_CIRCLE;
#include <string>
using std::string;
using std::to_string;
#include <utility>
using std::make_pair;
using std::pair;
#include <initializer_list>
using std::initializer_list;

Circle::Circle(int radius, BoundBoxType bound_box, PointType current_point)
    : radius(radius), Shape(bound_box, current_point) {}

void Circle::rotate(int rotation_angle) { rotateBoundBox(rotation_angle); }

void Circle::horizontal() {}

void Circle::vertical(const initializer_list<Shape> &list) {}

std::string Circle::toPostScript() {
  string ps_circle = DRAW_CIRCLE;
  ps_circle.replace(ps_circle.find(x_coord_str), x_coord_str.length(),
                    to_string(current_point.first));
  ps_circle.replace(ps_circle.find(y_coord_str), y_coord_str.length(),
                    to_string(current_point.second));
  ps_circle.replace(ps_circle.find(str_radius), str_radius.length(),
                    to_string(radius));
  return ps_circle;
}

int Circle::getRadius() { return radius; }

Circle cps::getCircle(Shape::PointType current_point, int radius) {
  auto bound_box = make_pair<double, double>(radius * 2.0, radius * 2.0);

  return Circle(radius, bound_box, current_point);
}
void Circle::setCurrentPoint(PointType new_point) { current_point = new_point; }
