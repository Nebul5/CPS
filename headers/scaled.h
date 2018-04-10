#ifndef SCALED_H
#define SCALED_H
#include "consts.h"
#include "shape.h"
using cps::MOVETO;
#include <string>
// std::string
// std::to_string;
#include <utility>
// std::pair

namespace cps {
class Scaled : public Shape {
public:
  using ScaleType = std::pair<double, double>;

private:
  ShapePtr shape;
  ScaleType scale;
  std::string scale_str = "x y scale \n";

public:
  Scaled() = default;
  Scaled(ShapePtr shape, ScaleType scale) : shape(shape), scale(scale) {
    scaleBoundBox();
    makeScaleStr();
  }

  std::string toPostScript() {
    auto shape_str = shape->toPostScript();
    shape_str.replace(shape_str.find(MOVETO), MOVETO.length(),
                      (MOVETO + scale_str));
    return shape_str;
  }
  ShapePtr getShape() const { return shape; }

private:
  void makeScaleStr() {
    scale_str = std::to_string(scale.first) + " " +
                std::to_string(scale.second) + " scale " + "\n";
  };
  void scaleBoundBox() {
    shape->setBoundBox(
        Shape::BoundBoxType(shape->getBoundBox().first * scale.first,
                            shape->getBoundBox().second * scale.second));
  }
};
} // namespace cps
#endif
