#include "../headers/shape.h"
using cps::Shape;
#include "../headers/polygon.h"
using cps::Polygon;
#include <string>
using std::string;
#include <utility>
using std::pair;

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
