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

Vertical::Vertical(initializer_list<shared_ptr<Shape>> shapes) {
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
  auto current_point = make_pair<int, int>(0, 0);
  int x;
  double width = 0;
  double height = 0;
  int y;
  for (int i = 1; i < vertical_shapes.size(); ++i) {
    x = vertical_shapes[0]->getCurrentPoint().first;
    cout << "x was " << x << endl;
    width = max(width, vertical_shapes[i]->getBoundBox().first);
    y = getNextYCoordinate(i);
    current_point = pair<int, int>(x, y);
    cout << "y was " << y << endl;
    cout << "calculated current point " << i << " was " << x << ", " << y
         << endl;
    vertical_shapes[i]->setCurrentPoint(current_point);
  }
  height = (vertical_shapes.back()->getCurrentPoint().second +
            vertical_shapes.back()->getBoundBox().second / 2.0);
  bound_box = Shape::BoundBoxType(width, height);
  cout << "width was " << width << endl;
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
