#include "../headers/shape.h"
using cps::Shape;
#include "../headers/multishape.h"
using cps::MultiShape;

#include <initializer_list>
using std::initializer_list;
#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <utility>
using std::make_pair;
using std::pair;
#include <vector>
using std::vector;

MultiShape::MultiShape(initializer_list<ShapePtr> shapes) : shapes(shapes) {}

string MultiShape::toPostScript() {
  string multishape_ps_string;
  for (int i = 0; i < shapes.size(); ++i) {
    multishape_ps_string += shapes[i]->toPostScript();
  }
  return multishape_ps_string;
}

void MultiShape::assembleShapes() {
  auto next_current_point = PointType(0, 0);
  int x, y;
  double width, height = 0;

  findCurrentPoint();
  for (auto i = 1; i < shapes.size(); ++i) {
    next_current_point = findNextCurrentPoint(i);
    shapes[i]->setCurrentPoint(next_current_point);
    getBoundBoxDimensionInLoop(i);
  }
  getBoundBoxDimension();
}

void MultiShape::findCurrentPoint() {
  current_point = shapes[0]->getCurrentPoint();
}

const vector<MultiShape::ShapePtr> MultiShape::getShapes() { return shapes; }

MultiShape::PointType MultiShape::findNextCurrentPoint(int i) {
  return make_pair(0, 0);
}
void MultiShape::getBoundBoxDimensionInLoop(int i) {}
void MultiShape::getBoundBoxDimension() {}
void MultiShape::findBoundBox() {}
