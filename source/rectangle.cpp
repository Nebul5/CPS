#include "../headers/shape.h"
using cps::Shape;
#include "../headers/rectangle.h"
using cps::Rectangle;
#include "../headers/consts.h"
using cps::DRAW_RECTANGLE;
using cps::INCH;
#include <string>
using std::string;
using std::to_string;
#include <utility>
using std::pair;

Rectangle::Rectangle(BoundBoxType bound_box, PointType current_point)
    : width(bound_box.first), height(bound_box.second),
      Shape(bound_box, current_point) {}

void Rectangle::rotate(unsigned int rotation_angle) {}

void Rectangle::horizontal() {}

void Rectangle::vertical() {}

string Rectangle::toPostScript() {
  string ps_rectangle = DRAW_RECTANGLE;
  ps_rectangle.replace(ps_rectangle.find(str_height), str_height.length(),
                       to_string(height));
  ps_rectangle.replace(ps_rectangle.find(str_width), str_width.length(),
                       to_string(width));

  return ps_rectangle;
}

unsigned int Rectangle::getWidth() { return width; }
unsigned int Rectangle::getHeight() { return height; }
