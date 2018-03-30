#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
// cps::Shape
// Shape::BoundBoxType
// Shape::PointType

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
  unsigned int width;
  unsigned int height;
  const std::string str_height = "height";
  const std::string str_width = "width";

public:
  Rectangle() = default;
  ~Rectangle() = default;
  Rectangle(BoundBoxType bound_box, PointType current_Point);
  virtual void rotate(unsigned int rotation_angle) override;
  virtual void scale(double x_scale, double y_scale) override;
  virtual void horizontal() override;
  virtual void vertical() override;
  virtual std::string toPostScript() override;

public:
  unsigned int getWidth();
  unsigned int getHeight();
};
} // namespace cps
#endif
