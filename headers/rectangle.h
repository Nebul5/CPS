#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
// cps::BoundBoxType
// cps::PointType

#include <string>
// std::string
#include <utility>
// std::pair

namespace cps {
class Rectangle : public Shape {
public:
  using Shape::BoundBoxType;
  using Shape::PointType;

private:
  int width;
  int height;

public:
  Rectangle() = default;
  Rectangle(BoundBoxType bound_Box, PointType current_Point);
  virtual void rotate(size_t rotation_angle) override;
  virtual void scale(double x_scale, double y_scale) override;
  virtual void horizontal() override;
  virtual void vertical() override;
  virtual std::string toPostScript() override;

public:
  int getWidth();
  int getHeight();
};
} // namespace cps
#endif
