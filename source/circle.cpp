#include "../headers/shape.h"
using cps::Shape;
#include "../headers/circle.h"
using cps::Circle;
#include <string>
using std::string;
#include <utility>
using std::pair;

Circle::Circle(int radius, BoundBoxType bound_box, PointType current_point)
    : radius(radius), Shape(bound_box, current_point) {}

void Circle::rotate(int rotation_angle) {}

void Circle::scale(double x_scale, double y_scale) {}

void Circle::horizontal() {}

void Circle::vertical() {}

std::string Circle::toPostScript() {
  string rv = "to define";
  return rv;
}

int Circle::getRadius() { return radius; }
