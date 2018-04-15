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
private:
  int radius;
  const std::string str_radius = "radius";

public:
  Circle() = default;
  ~Circle() = default;
  Circle(int radius, BoundBoxType bound_box, PointType current_point);
  virtual void rotate(int rotation_angle) override;
  virtual std::string toPostScript() override;

public:
  int getRadius();
  virtual void setCurrentPoint(PointType new_point) override;
};
Circle getCircle(Shape::PointType current_point, int radius);
} // namespace cps
#endif
