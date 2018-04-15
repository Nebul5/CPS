#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
// cps::Shape
// Shape::BoundBoxType
// Shape::PointType
#include <initializer_list>
// std::initializer_list
#include <string>
// std::string
#include <utility>
// std::pair

namespace cps {
class Rectangle : public Shape {
private:
  int width;
  int height;
  const std::string str_height = "height";
  const std::string str_width = "width";

public:
  Rectangle() = default;
  ~Rectangle() = default;
  Rectangle(BoundBoxType bound_box, PointType current_Point);
  virtual void rotate(int rotation_angle) override;
  virtual std::string toPostScript() override;

public:
  int getWidth();
  int getHeight();
  virtual void setCurrentPoint(PointType new_point) override;
};
} // namespace cps
#endif
