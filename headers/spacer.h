#ifndef SPACER_H
#define SPACER_H
#include "shape.h"
// cps::Shape
#include <string>
// std::string
namespace cps {
class Spacer : public Shape {
private:
  double width;
  double height;
  const std::string str_height = "height";
  const std::string str_width = "width";

public:
  Spacer() = default;
  ~Spacer() = default;
  Spacer(PointType current_point, double width, double height);
  virtual std::string toPostScript() override;
};
} // namespace cps
#endif
