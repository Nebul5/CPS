#ifndef SHAPE_H
#define SHAPE_H

#include <string>
// std::string
#include <utility>
// std::pair

// This is the Shape Base class that Circle, Rectangle and Regular Polygon
// Inherit from
namespace cps {
class Shape {
public:
  using BoundBoxType = std::pair<unsigned int, unsigned int>;
  using PointType = std::pair<unsigned int, unsigned int>;

private:
  BoundBoxType bound_box;  // bound_Box(width,height)
  PointType current_point; // current_Point(x,y)
  std::string scale_str = "1 1 scale";

public:
  Shape() = default;
  ~Shape() = default;
  Shape(BoundBoxType bound_box, PointType current_point);
  void scale(double x_Scale, double y_Scale);
  virtual void rotate(unsigned int rotation_Angle);
  virtual void vertical();
  virtual void horizontal();
  void layer();

  virtual std::string toPostScript() = 0;

  BoundBoxType getBoundBox();
  PointType getCurrentPoint();
};

// Stores a syntax tree representing a postscript program
struct SyntaxTree {
  // TODO
};

// Stores a postscript program whose source is a string written in standard C++
class Program {
private:
  SyntaxTree AST;

public:
  Program(std::string source);
  Program(const Program &p);

  std::string toString();

  void interpret(std::string source);
};
} // namespace cps

#endif
