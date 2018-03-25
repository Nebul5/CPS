#include "../headers/circle.h"
using cps::Circle;

#include "../headers/rectangle.h"
using cps::Rectangle;

#include <iostream>
using std::cout;
using std::endl;
#include <utility>
using std::make_pair;
using std::pair;

int main() {
  int rad = 5;
  Circle::BoundBoxType bound_box = make_pair(10, 10);
  Circle::PointType current_point = make_pair(0, 0);
  auto test_circ = Circle(rad, bound_box, current_point);
  cout << test_circ.toPostScript() << endl;
  return 0;
}
