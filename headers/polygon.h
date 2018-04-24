#ifndef POLYGON_H
#define POLYGON_H
#include "shape.h"
// cps::Shape
// Shape::BoundBoxType
// Shape::PointType

#include <string>
// std::string
#include <utility>
// std::pair
#include <initializer_list>
// std::initializer_list

namespace cps {
class Polygon : public Shape {
private:
  int number_sides;
  int side_length;
  const std::string number_sides_str = "number_sides";
  const std::string side_length_str = "side_length";

public:
  Polygon() = default;
  ~Polygon() = default;
  bool operator==(const Polygon &rhs) const;
  Polygon(BoundBoxType bound_Box, PointType current_Point, int number_sides,
          int side_length);
  virtual void rotate(int rotation_angle) override;
  virtual std::string toPostScript() override;

public:
  int getNumberOfSides();
  int getSideLength();
  virtual void setCurrentPoint(PointType new_point) override;
  void rotateStartingPoint(int angle);

private:
  void setStartingPoint();
};

Shape::BoundBoxType make_Bounding_Box(int number_sides, int side_length);
Polygon getPolygon(Shape::PointType current_point, int number_sides,
                   int side_length);
} // namespace cps
#endif
