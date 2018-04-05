#ifndef VERTICAL_H
#define VERTICAL_H
#include "shape.h"
// cps::Shape
#include <initializer_list>
// std::initializer_list
#include <vector>
// std::vector
#include <memory>
// std::shared_ptr
#include <utility>
// std::pair

namespace cps {
class Vertical {
  using BoundBoxType = std::pair<double, double>;
  using ShapePtr = Shape::ShapePtr;

private:
  std::vector<ShapePtr> vertical_shapes;
  BoundBoxType bound_box;

public:
  Vertical() = default;
  ~Vertical() = default;
  Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes);
  std::string toPostScript();
  void assembleShapes();
  const std::vector<std::shared_ptr<Shape>> getShapes();
  const BoundBoxType getBoundBox();

private:
  int getNextYCoordinate(int i);
};
} // namespace cps
#endif
