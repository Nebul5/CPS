#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"
// cps::Shape
// Shape::BoundBoxType
// Shape::PointType

#include <string>
// std::string
#include <utility>
// std::pair
#include <initializer_list>
// std::initializer_list

namespace cps {
class Circle : public Shape {
public:
  using Shape::BoundBoxType;
  using Shape::PointType;

private:
  int radius;
  const std::string str_radius = "radius";

public:
  Circle() = default;
  ~Circle() = default;
  Circle(int radius, BoundBoxType bound_box, PointType current_point);
  virtual void rotate(int rotation_angle) override;
  virtual void horizontal() override;
  virtual void vertical(const std::initializer_list<Shape> &list) override;
  virtual std::string toPostScript() override;

public:
  int getRadius();
};
Circle getCircle(Shape::PointType current_point, int radius);
} // namespace cps
#endif
