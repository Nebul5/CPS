#ifndef SPACER_H
#define SPACER_H
#include "shape.h"
// cps::Shape
namespace cps {
class Spacer : public Shape {
public:
  Spacer() = default;
  ~Spacer() = default;
  BoundBoxType dothin();
};
} // namespace cps
#endif
