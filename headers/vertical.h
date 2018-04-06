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
class Vertical : public Shape {
  using Shape::BoundBoxType;
  using Shape::PointType;
  using Shape::ShapePtr;

private:
  std::vector<ShapePtr> vertical_shapes;

public:
  Vertical() = default;
  ~Vertical() = default;
  Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes);
  std::string toPostScript();
  const std::vector<std::shared_ptr<Shape>> getShapes();
  const BoundBoxType getBoundBox();

private:
  void assembleShapes();
  int getNextYCoordinate(int i);
};
} // namespace cps
#endif
