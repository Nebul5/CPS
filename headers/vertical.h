#ifndef VERTICAL_H
#define VERTICAL_H
#include "shape.h"
// cps::Shape
#include "multishape.h"
// cps::MultiShape
#include <initializer_list>
// std::initializer_list
#include <vector>
// std::vector
#include <memory>
// std::shared_ptr
#include <utility>
// std::pair

namespace cps {
class Vertical : public MultiShape {
public:
  Vertical() = default;
  ~Vertical() = default;
  Vertical(std::initializer_list<ShapePtr> shapes);

protected:
  virtual PointType findNextCurrentPoint(int i) override;
  virtual void getBoundBoxDimensionInLoop(int i) override;
  virtual void getBoundBoxDimension() override;
};
} // namespace cps
#endif
