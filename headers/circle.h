#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
// cps::Shape
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
  Circle(int radius, BoundBoxType bound_box, PointType current_point);
  virtual void rotate(int rotation_angle) override;
  virtual void scale(double x_scale, double y_scale) override;
  virtual void horizontal() override;
  virtual void vertical() override;
  virtual std::string toPostScript() override;
};
} // namespace cps
#endif
