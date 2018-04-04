#ifndef SCALED_H
#define SCALED_H
#include "shape.h"
#include <string>
// std::string
// std::to_string;
#include <utility>
// std::pair

namespace cps {
template <typename shape_type> class Scaled {
public:
  using ScaleType = std::pair<double, double>;

private:
  shape_type shape;
  ScaleType scale;
  std::string scale_str = "scale x y\n";

public:
  Scaled() = default;
  Scaled(shape_type shape, ScaleType scale) : shape(shape), scale(scale) {
    scaleBoundBox();
    makeScaleStr();
  }

  std::string toPostScript() { return scale_str + shape.toPostScript(); }
  shape_type getShape() const { return shape; }

private:
  void makeScaleStr() {
    scale_str = "scale " + std::to_string(scale.first) + " " +
                std::to_string(scale.second) + "\n";
  };
  void scaleBoundBox() {
    shape.setBoundBox(
        Shape::BoundBoxType(shape.getBoundBox().first * scale.first,
                            shape.getBoundBox().second * scale.second));
  }
};
} // namespace cps
#endif
