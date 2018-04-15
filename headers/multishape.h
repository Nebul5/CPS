#ifndef MULTISHAPE_H
#define MULTISHAPE_H
#include "shape.h"
// cps::Shape

#include <initializer_list>
// std::initializer_list
#include <string>
// std::string
#include <memory>
// std::memory
#include <vector>
// std::vector

namespace cps {
class MultiShape : public Shape {
protected:
  std::vector<ShapePtr> shapes;

public:
  MultiShape() = default;
  ~MultiShape() = default;

  MultiShape(std::initializer_list<ShapePtr> shape_list);
  virtual std::string toPostScript() override;

protected:
  void findCurrentPoint();
  virtual PointType findNextCurrentPoint(int i);
  virtual void findBoundBox();
  virtual void getBoundBoxDimensionInLoop(int i);
  virtual void getBoundBoxDimension();

  const std::vector<std::shared_ptr<Shape>> getShapes();
  void assembleShapes();
};
} // namespace cps
#endif
