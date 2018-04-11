#include "../headers/spacer.h"
using cps::Spacer;
#include "../headers/shape.h"
using cps::Shape;
#include "../headers/consts.h"
using cps::DRAW_SPACER;

#include <string>
using std::string;
using std::to_string;

#include <utility>
using std::make_pair;
using std::pair;

Spacer::Spacer(PointType current_point, double width, double height)
    : width(width), height(height),
      Shape(current_point, make_pair(width, height)) {}
string Spacer::toPostScript() {
  string ps_spacer = DRAW_SPACER;
  ps_spacer.replace(ps_spacer.find(str_width), str_width.length(),
                    to_string(width));
  ps_spacer.replace(ps_spacer.find(str_height), str_height.length(),
                    to_string(height));

  return ps_spacer;
}
