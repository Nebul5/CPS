#ifndef HORIZONTAL_H
#define HORIZONTAL_H
#include "multishape.h"
// cps::MultiShape

#include <string>
// std::string
#include <vector>
// std::vector
#include <initializer_list>
// std::initializer_list

namespace cps {
class Horizontal : public MultiShape {
public:
  Horizontal() = default;
  ~Horizontal() = default;
  Horizontal(std::initializer_list<ShapePtr> shapes);

protected:
  virtual PointType findNextCurrentPoint(int i) override;
  virtual void getBoundBoxDimensionInLoop(int i) override;
  virtual void getBoundBoxDimension() override;
};
} // namespace cps
#endif
