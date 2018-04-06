#include "../headers/consts.h"
using cps::ROTATE;
#include "../headers/shape.h"
using cps::Shape;
#include "../headers/rotated.h"
using cps::Rotated;
#include <cmath>
#include <string>
using std::string;
using std::to_string;
#include <stdexcept>
using std::out_of_range;
#include <utility>
using std::make_pair;
using std::pair;

Rotated::Rotated(ShapePtr shape, int angle) {
  if (!isValidAngle(angle)) {
    throw(out_of_range("angle must be multiple of 90!"));
  }
  this->shape = shape;
  rotation_angle = angle;
  shape->rotate(rotation_angle);
  bound_box = shape->getBoundBox();
  current_point = shape->getCurrentPoint();
  getRotationStr();
}
bool Rotated::isValidAngle(int angle) {
  return !(angle % 90 != 0 || angle > 270);
}

Rotated::ShapePtr Rotated::getShape() { return shape; }

string Rotated::toPostScript() {
  auto shape_str = shape->toPostScript();
  shape_str.replace(shape_str.find(MOVETO), MOVETO.length(),
                    (MOVETO + rotation_str));
  return shape_str;
}

void Rotated::getRotationStr() {
  rotation_str = to_string(rotation_angle) + " " + ROTATE;
}
