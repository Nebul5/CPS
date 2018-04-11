#include "../headers/shape.h"
using cps::Shape;
#include "../headers/layered.h"
using cps::Layered;

#include <algorithm>
using std::max;
#include <initializer_list>
using std::initializer_list;
#include <string>
using std::string;
#include <utility>
using std::make_pair;
#include <vector>
using std::vector;

Layered::Layered(initializer_list<ShapePtr> shapes) {
  layered_shapes = shapes;
  assembleShapes();
}

void Layered::assembleShapes() {
  current_point = layered_shapes[0]->getCurrentPoint();
  double width = 0;
  double height = 0;
  for (auto i = 1; i < layered_shapes.size(); ++i) {
    layered_shapes[i]->setCurrentPoint(current_point);
    width = max(width, layered_shapes[i]->getBoundBox().first);
    height = max(height, layered_shapes[i]->getBoundBox().second);
  }
  bound_box = make_pair(width, height);
}

string Layered::toPostScript() {
  string layered_ps_string;
  for (int i = 0; i < layered_shapes.size(); ++i) {
    layered_ps_string += layered_shapes[i]->toPostScript();
  }
  return layered_ps_string;
}
