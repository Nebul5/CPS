#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
// cps::BoundBoxType
// cps::PointType

#include <string>
// std::string
#include <utility>
// std::pair

namespace cps {
class Circle : public Shape {
public:
  using Shape::BoundBoxType;
  using Shape::PointType;

private:
  int radius;

public:
  Circle() = default;
  Circle(int radius, BoundBoxType bound_Box, PointType current_Point);
  virtual void rotate(int rotation_angle) override;
  virtual void scale(double x_scale, double y_scale) override;
  virtual void horizontal() override;
  virtual void vertical() override;
};
} // namespace cps
#endif
