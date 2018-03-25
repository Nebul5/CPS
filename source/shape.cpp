#include "../headers/shape.h"
using cps::Shape;

Shape::Shape(BoundBoxType bound_box, PointType current_point)
    : bound_box(bound_box), current_point(current_point) {}

void Shape::layer() {}

Shape::BoundBoxType Shape::getBoundBox() { return bound_box; }
Shape::PointType Shape::getCurrentPoint() { return current_point; }
