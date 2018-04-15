#include "../headers/horizontal.h"
using cps::Horizontal;
#include "../headers/multishape.h"
using cps::MultiShape;

#include <algorithm>
using std::max;
#include <string>
using std::string;
#include <initializer_list>
using std::initializer_list;
#include <utility>
using std::make_pair;
using std::pair;

Horizontal::Horizontal(initializer_list<ShapePtr> shapes) : MultiShape(shapes) {
  assembleShapes();
}

Horizontal::PointType Horizontal::findNextCurrentPoint(int i) {
  int x = ((shapes[i - 1]->getCurrentPoint().first +
            (shapes[i - 1]->getBoundBox().first / 2.0)) +
           (shapes[i]->getBoundBox().first / 2.0));
  int y = shapes[0]->getCurrentPoint().second;
  return PointType(x, y);
}

void Horizontal::getBoundBoxDimensionInLoop(int i) {
  bound_box.second = max(shapes[i]->getBoundBox().second, bound_box.second);
}
void Horizontal::getBoundBoxDimension() {
  bound_box.first = (shapes.back()->getCurrentPoint().first +
                     shapes.back()->getBoundBox().first / 2.0);
}
