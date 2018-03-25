#ifndef SHAPE_H
#define SHAPE_H

#include "consts.h"
#include <cstddef>
#include <string>
// std::string
#include <utility>
// std::pair

// This is the Shape Base class that Circle, Rectangle and Regular Polygon
// Inherit from
namespace cps {
class Shape {
public:
  using BoundBoxType = std::pair<int, int>;
  using PointType = std::pair<int, int>;

private:
  BoundBoxType bound_box;  // bound_Box(width,height)
  PointType current_point; // current_Point(x,y)
public:
  Shape() = default;
  Shape(BoundBoxType bound_box, PointType current_point);
  virtual void rotate(int rotation_Angle) = 0;
  virtual void scale(double x_Scale, double y_Scale) = 0;
  virtual void vertical() = 0;
  virtual void horizontal() = 0;
  void layer();

  virtual std::string toPostScript() = 0;
};
} // namespace cps

#endif
