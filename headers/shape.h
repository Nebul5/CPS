#ifndef SHAPE_H
#define SHAPE_H

#include "consts.h"
#include<utility>
#include<cstddef>

//THis is the Shape Base class that Circle, Rectangle and Regular Polygon Inherit from
namespace cps{
  class Shape
  {
  private:
    std::pair<int,int> bound_Box;  //bound_Box(width,height)
    std::pair<int, int> current_Point; //current_Point(x,y)

  public:
    virtual void Rotated(Shape shape, int rotation_Angle);
    virtual void Scaled(Shape shape, double x_Scale, double y_Scale);
    void Layered();
    void Vertical();
    void Horizontal();

  };
}

#endif
