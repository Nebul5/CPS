#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::Polygon;
#include <string>
using std::string;
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

void Polygon::scale(double x_scale, double y_scale) {}

void Polygon::horizontal() {}

void Polygon::vertical() {}

string Polygon::toPostScript() {
  auto rv = "to define";
  return rv;
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
