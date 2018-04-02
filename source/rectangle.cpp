#include "../headers/shape.h"
using cps::Shape;
#include "../headers/rectangle.h"
using cps::Rectangle;
#include "../headers/consts.h"
using cps::DRAW_RECTANGLE;
using cps::INCH;
#include <initializer_list>
using std::initializer_list;
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

void Rectangle::vertical(const initializer_list<Shape> &list) {}

string Rectangle::toPostScript() {
  string ps_rectangle = DRAW_RECTANGLE;
  ps_rectangle.replace(ps_rectangle.find(x_coord_str), x_coord_str.length(),
                       to_string(current_point.first));
  ps_rectangle.replace(ps_rectangle.find(y_coord_str), y_coord_str.length(),
                       to_string(current_point.second));
  ps_rectangle.replace(ps_rectangle.find(str_height), str_height.length(),
                       to_string(height));
  ps_rectangle.replace(ps_rectangle.find(str_width), str_width.length(),
                       to_string(width));

  return ps_rectangle;
}

unsigned int Rectangle::getWidth() { return width; }
unsigned int Rectangle::getHeight() { return height; }
