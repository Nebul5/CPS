#include "../headers/shape.h"
using cps::Shape;
#include "../headers/horizontal.h"
using cps::Horizontal;

#include <algorithm>
using std::max;
#include <string>
using std::string;
#include <initializer_list>
using std::initializer_list;
#include <utility>
using std::make_pair;
using std::pair;

Horizontal::Horizontal(initializer_list<ShapePtr> shapes) {
  horizontal_shapes = shapes;
  assembleShapes();
}

int Horizontal::getNextXCoordinate(int i) {
  int x = ((horizontal_shapes[i - 1]->getCurrentPoint().first +
            (horizontal_shapes[i - 1]->getBoundBox().first / 2.0)) +
           (horizontal_shapes[i]->getBoundBox().first / 2.0));
  return x;
}

void Horizontal::assembleShapes() {
  auto active_point = make_pair<int, int>(0, 0);
  int x, y;
  double width, height = 0;
  current_point = horizontal_shapes[0]->getCurrentPoint();
  for (auto i = 1; i < horizontal_shapes.size(); ++i) {
    y = horizontal_shapes[0]->getCurrentPoint().second;
    height = max(height, horizontal_shapes[i]->getBoundBox().second);
    x = getNextXCoordinate(i);
    active_point = PointType(x, y);
    horizontal_shapes[i]->setCurrentPoint(active_point);
  }
  width = (horizontal_shapes.back()->getCurrentPoint().first +
           horizontal_shapes.back()->getBoundBox().first / 2.0);
  bound_box = BoundBoxType(width, height);
}

string Horizontal::toPostScript() {
  string horizontal_ps_string;
  for (auto i = 0; i < horizontal_shapes.size(); ++i) {
    horizontal_ps_string += horizontal_shapes[i]->toPostScript();
  }
  return horizontal_ps_string;
}
