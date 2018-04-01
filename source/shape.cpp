#include "../headers/shape.h"
using cps::Program;
using cps::Shape;
#include <string>
using std::string;
using std::to_string;

Shape::Shape(BoundBoxType bound_box, PointType current_point)
    : bound_box(bound_box), current_point(current_point) {}

void Shape::layer() {}
void Shape::scale(double x_scale, double y_scale) {
  scale_str = to_string(x_scale) + " " + to_string(y_scale) + " scale\n";
}
void Shape::rotate(unsigned int rotation_Angle) {}
void Shape::vertical() {}
void Shape::horizontal() {}
string Shape::toPostScript() { return "don't even think about using me"; }
Shape::BoundBoxType Shape::getBoundBox() { return bound_box; }
Shape::PointType Shape::getCurrentPoint() { return current_point; }
void Shape::setCurrentPoint(Shape::PointType new_point) {
  current_point = new_point;
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
