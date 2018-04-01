#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include<initializer_list>
using std::initializer_list;
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

protected:
  BoundBoxType bound_box;  // bound_Box(width,height)
  PointType current_point; // current_Point(x,y)
  std::string scale_str = "1 1 scale";
  std::string x_coord_str = "x_coord";
  std::string y_coord_str = "y_coord";

public:
  Shape() = default;
  ~Shape() = default;
  Shape(BoundBoxType bound_box, PointType current_point);
  void scale(double x_Scale, double y_Scale);
  virtual void rotate(unsigned int rotation_Angle);
  virtual void vertical(const initializer_list<Shape> & list); 
  virtual void horizontal();
  void layer();

pair<int, int> max_Dimension(const initializer_list<Shape> &list)


  virtual std::string toPostScript() = 0;

  BoundBoxType getBoundBox();
  PointType getCurrentPoint();
   BoundBoxType getBoundBox()const;
  PointType getCurrentPoint()const;
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
