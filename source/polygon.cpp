#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::Polygon;
#include "../headers/consts.h"
using cps::DRAW_POLYGON;
#include <string>
using std::string;
using std::to_string;
#include <utility>
using std::make_pair;
using std::pair;
#include <math.h> // sin and ceil

#define PI 3.14159265

Polygon::Polygon(BoundBoxType bound_box, PointType current_point,
                 unsigned int number_sides, unsigned int side_length)
    : number_sides(number_sides), side_length(side_length),
      Shape(bound_box, current_point) {}

void Polygon::rotate(unsigned int rotation_angle) {}

void Polygon::horizontal() {}

void Polygon::vertical() {}

string Polygon::toPostScript() {
  string ps_polygon = DRAW_POLYGON;
  ps_polygon.replace(ps_polygon.find(number_sides_str),
                     number_sides_str.length(), to_string(number_sides));
  ps_polygon.replace(ps_polygon.find(side_length_str), side_length_str.length(),
                     to_string(side_length));
  return ps_polygon;
}

unsigned int Polygon::getNumberOfSides() { return number_sides; }
unsigned int Polygon::getSideLength() { return side_length; }

Polygon cps::getPolygon(Shape::PointType current_point,
                        unsigned int number_sides, unsigned int side_length) {
  auto denominator = sin(PI / double(number_sides));
  unsigned int radius = abs(ceil(double(side_length) / denominator));
  auto bound_box = make_pair(radius, radius);
  return Polygon(bound_box, current_point, number_sides, side_length);
}
