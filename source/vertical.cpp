#include "../headers/shape.h"
using cps::Shape;
#include "../headers/vertical.h"
using cps::Vertical;
#include <algorithm>
using std::max;
#include <iostream>
using std::cout;
using std::endl;
#include <string>
using std::string;
#include <memory>
using std::shared_ptr;
#include <utility>
using std::make_pair;
using std::pair;
#include <vector>
using std::vector;

#include <initializer_list>
using std::initializer_list;

Vertical::Vertical(initializer_list<ShapePtr> shapes) {
  vertical_shapes = shapes;
  assembleShapes();
}

int Vertical::getNextYCoordinate(int i) {
  int y = ((vertical_shapes[i - 1]->getCurrentPoint().second +
            (vertical_shapes[i - 1]->getBoundBox().second / 2.0)) +
           (vertical_shapes[i]->getBoundBox().second / 2.0));
  return y;
}

void Vertical::assembleShapes() {
  auto active_point = make_pair<int, int>(0, 0);
  int x, y;
  double width, height = 0;
  current_point = vertical_shapes[0]->getCurrentPoint();
  for (auto i = 1; i < vertical_shapes.size(); ++i) {
    x = vertical_shapes[0]->getCurrentPoint().first;
    width = max(width, vertical_shapes[i]->getBoundBox().first);
    y = getNextYCoordinate(i);
    active_point = PointType(x, y);
    vertical_shapes[i]->setCurrentPoint(active_point);
  }
  height = (vertical_shapes.back()->getCurrentPoint().second +
            vertical_shapes.back()->getBoundBox().second / 2.0);
  bound_box = BoundBoxType(width, height);
}

string Vertical::toPostScript() {
  string vertical_ps_string;
  for (int i = 0; i < vertical_shapes.size(); ++i) {
    vertical_ps_string += vertical_shapes[i]->toPostScript();
  }
  return vertical_ps_string;
}

const vector<shared_ptr<Shape>> Vertical::getShapes() {
  return vertical_shapes;
}
const Vertical::BoundBoxType Vertical::getBoundBox() { return bound_box; }
