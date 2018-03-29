// **************************************** //
//                Shape.h                   //
//        Header for Shape language         //
// by Paul Huske, Hal ... , and Jake Conner //
// **************************************** //

#include <utility>
#include <cstddef>
#include <tuple>
#include <string>

//THis is the Shape Base class that Circle, Rectangle and Regular Polygon Inherit from
class Shape{
private:
	std::tuple<int,int> bound_Box;  //bound_Box(width,height)
	std::tuple<int, int> current_Point; //current_Point(x,y)

public:
	virtual void Rotated(Shape shape, int rotation_Angle);
	virtual void Scaled(Shape shape, double x_Scale, double y_Scale);
	void Layered();
	void Vertical();
	void Horizontal();
	float max_Dimension();
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
	Program(const Program & p);

	std::string toString();
	
	void interpret(std::string source);
};

// NOTE: I think we should try to keep our objects in a single header 
//	since all the client really needs is the "Program" object. 

//	Including separate headers in the Shape implementation is
//	always an option if the file gets too big.

//		- Jake