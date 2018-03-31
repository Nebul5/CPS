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

Circle::Circle(unsigned int radius, BoundBoxType bound_box,
               PointType current_point)
    : radius(radius), Shape(bound_box, current_point) {}

void Circle::rotate(unsigned int rotation_angle) {}

void Circle::horizontal() {}

void Circle::vertical() {}

std::string Circle::toPostScript() {
  string ps_circle = DRAW_CIRCLE;
  ps_circle.replace(ps_circle.find(str_radius), str_radius.length(),
                    to_string(radius));
  return ps_circle;
}

int Circle::getRadius() { return radius; }

Circle cps::getCircle(Shape::PointType current_point, unsigned int radius) {
  auto bound_box =
      make_pair<unsigned int, unsigned int>(radius * 2, radius * 2);

  return Circle(radius, bound_box, current_point);
}
