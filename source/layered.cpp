#include "../headers/multishape.h"
using cps::MultiShape;
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

Layered::Layered(initializer_list<ShapePtr> shapes) : MultiShape(shapes) {
  assembleShapes();
}
Layered::PointType Layered::findNextCurrentPoint(int i) {
  return current_point;
}
void Layered::getBoundBoxDimensionInLoop(int i) {
  bound_box.first = max(shapes[i]->getBoundBox().first, bound_box.first);
  bound_box.second = max(shapes[i]->getBoundBox().second, bound_box.second);
}
