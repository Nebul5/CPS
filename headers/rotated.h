#ifndef ROTATED_H
#define ROTATED_H
#include "shape.h"
// cps::Shape
#include <string>
// std::string
#include <memory>
// std::shared_ptr
#include <utility>
// std::pair

namespace cps {
class Rotated {
public:
  using PointType = Shape::PointType;
  using ShapePtr = Shape::ShapePtr;

private:
  int rotation_angle;
  ShapePtr shape;
  std::string rotation_str;

public:
  Rotated() = default;
  ~Rotated() = default;
  Rotated(ShapePtr shape, int angle);
  ShapePtr getShape();
  std::string toPostScript();

private:
  void getRotationStr();
  bool isValidAngle(int angle);
};
} // namespace cps
#endif
