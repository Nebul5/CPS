#include "../headers/shape.h"
using cps::Shape;
#include "../headers/vertical.h"
using cps::Vertical;
#include "../headers/multishape.h"
using cps::MultiShape;
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

Vertical::Vertical(initializer_list<ShapePtr> shapes) : MultiShape(shapes) {
  assembleShapes();
}

Vertical::PointType Vertical::findNextCurrentPoint(int i) {
  auto x = shapes[0]->getCurrentPoint().first;
  auto y = ((shapes[i - 1]->getCurrentPoint().second +
             (shapes[i - 1]->getBoundBox().second / 2.0)) +
            (shapes[i]->getBoundBox().second / 2.0));
  return PointType(x, y);
}

void Vertical::getBoundBoxDimensionInLoop(int i) {
  bound_box.first = max(shapes[i]->getBoundBox().first, bound_box.second);
}
void Vertical::getBoundBoxDimension() {
  bound_box.second = (shapes.back()->getCurrentPoint().second +
                      shapes.back()->getBoundBox().first / 2.0);
}
