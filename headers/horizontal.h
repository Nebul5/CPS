#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "shape.h"
// cps::Shape

#include <string>
// std::string
#include <vector>
// std::vector
#include <initializer_list>
// std::initializer_list

namespace cps {
class Horizontal : public Shape {
public:
private:
  std::vector<ShapePtr> horizontal_shapes;

public:
  Horizontal() = default;
  ~Horizontal() = default;
  Horizontal(std::initializer_list<ShapePtr> shapes);
  virtual std::string toPostScript() override;

private:
  void assembleShapes();
  int getNextXCoordinate(int i);
};
} // namespace cps
#endif
