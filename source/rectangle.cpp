#include "../headers/shape.h"
using cps::Shape;
#include "../headers/rectangle.h"
using cps::Rectangle;
#include <string>
using std::string;
#include <utility>
using std::pair;

Rectangle::Rectangle(BoundBoxType bound_box, PointType current_point)
    : width(bound_box.first), height(bound_box.second),
      Shape(bound_box, current_point) {}

void Rectangle::rotate(size_t rotation_angle) {}

void Rectangle::scale(double x_scale, double y_scale) {}

void Rectangle::horizontal() {}

void Rectangle::vertical() {}

string Rectangle::toPostScript() {
  auto rv = "to define";
  return rv;
}

int Rectangle::getWidth() { return width; }
int Rectangle::getHeight() { return height; }
