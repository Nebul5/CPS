#ifndef LAYERED_H
#define LAYERED_H
#include "shape.h"
// cps::Shape

#include <initializer_list>
// std::initializer_list
#include <string>
// std::string
#include <vector>
// std::vector

namespace cps {
class Layered : public Shape {
private:
  std::vector<ShapePtr> shapes;

public:
  Layered() = default;
  ~Layered() = default;
  Layered(std::initializer_list<ShapePtr> layered_shapes);
  virtual std::string toPostScript() override;

private:
  void assembleShapes();
};
} // namespace cps
#endif
