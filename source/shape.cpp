#include "../headers/shape.h"
using cps::Program;
using cps::Shape;
#include <string>
using std::string;
using std::to_string;
#include <initializer_list>
using std::initializer_list;
#include <utility>
using std::make_pair;
using std::pair;

Shape::Shape(BoundBoxType bound_box, PointType current_point)
    : bound_box(bound_box), current_point(current_point) {}

void Shape::layer() {}
void Shape::scale(double x_scale, double y_scale) {
  scale_str = to_string(x_scale) + " " + to_string(y_scale) + " scale\n";
}
void Shape::rotate(int rotation_Angle) {}
void Shape::vertical(const initializer_list<Shape> &list) {
  bound_box = maxDimensions(list);
}
void Shape::horizontal() {}

Shape::BoundBoxType Shape::getBoundBox() { return bound_box; }
Shape::PointType Shape::getCurrentPoint() { return current_point; }
Shape::BoundBoxType Shape::getBoundBox() const { return bound_box; }
Shape::PointType Shape::getCurrentPoint() const { return current_point; }

void Shape::setBoundBox(BoundBoxType bound_box) { bound_box = bound_box; }
void Shape::setCurrentPoint(PointType new_point) { current_point = new_point; }

string Shape::toPostScript() {
  string ps_string = "improper use of toPostScript in base Shape Class";
  return ps_string;
}
Shape::BoundBoxType Shape::maxDimensions(const initializer_list<Shape> &list) {
  Shape::BoundBoxType max_dimensions = std::make_pair(0, 0);
  for (auto &itm : list) {
    auto b_Box = itm.getBoundBox();
    if (max_dimensions.first < b_Box.first)
      max_dimensions.first = b_Box.first;
    if (max_dimensions.second < b_Box.second)
      max_dimensions.second = b_Box.second;
  }
  return max_dimensions;
}

// Program constructor, takes a string of source code
Program::Program(std::string source) { interpret(source); }

Program::Program(const Program &p) { this->AST = p.AST; }

// toString, returns a string representation of the program that is a valid
// postscript program
std::string Program::toString() {
  // NOTE I don't think AST is a relevant
  // implementation concept for this project
  // there's no recursive grammer for this 'language'
  // except for compound shapes. but it's essentially just iteratively adding
  // each shape's postscript to a file.
  return "newpath \n 0 0 5 0 360 arc closepath stroke showpage";
}

// interpret, takes a string of source code and converts it to postscript
void Program::interpret(std::string source) {
  // TODO build AST from source
}
