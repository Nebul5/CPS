#ifndef SHAPE_H
#define SHAPE_H

#include "consts.h"
#include <cstddef>
#include <string>
#include <utility>

// This is the Shape Base class that Circle, Rectangle and Regular Polygon
// Inherit from
namespace cps {
class Shape {
public:
  using BoundBoxType = std::pair<int, int>;
  using PointType = std::pair<int, int>;

private:
  BoundBoxType bound_Box;  // bound_Box(width,height)
  PointType current_Point; // current_Point(x,y)

public:
  virtual void rotate(int rotation_Angle);
  virtual void scale(double x_Scale, double y_Scale);
  virtual void vertical();
  virtual void horizontal();
  void layer();

  virtual std::string to_postscript();
};
} // namespace cps

#endif
