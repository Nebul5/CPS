
//THis is the Shape Base class that Circle, Rectangle and Regular Polygon Inherit from
class Shape
{


public:

virtual void Rotated(Shape shape, int rotation_Angle);
virtual void Scaled(Shape shape, double x_Scale, double y_Scale);
void Layered();
void Vertical();
void Horizontal();

};
