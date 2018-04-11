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
private:
  std::vector<ShapePtr> vertical_shapes;

public:
  Vertical() = default;
  ~Vertical() = default;
  Vertical(std::initializer_list<std::shared_ptr<Shape>> shapes);
  virtual std::string toPostScript() override;
  const std::vector<std::shared_ptr<Shape>> getShapes();

private:
  void assembleShapes();
  int getNextYCoordinate(int i);
};
} // namespace cps
#endif
