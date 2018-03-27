// **************************************** //
//               Shape.cpp                  //
//     Implementation for Shape language    //
// by Paul Huske, Hal ... , and Jake Conner //
// **************************************** //

#include<utility>
#include<cstddef>
#include "Shape.h"

void Shape::Rotated(Shape shape, int rotation_Angle) {
	// TODO
}

void Shape::Scaled(Shape shape, double x_Scale, double y_Scale) {
	// TODO
}

void Shape::Layered() {
	// TODO
}

void Shape::Vertical() {
	// TODO
}

void Shape::Horizontal() {
	// TODO
}

// Program constructor, takes a string of source code
Program::Program(std::string source) { 
	interpret(source);
}

// Program copy constructor
Program::Program(const Program & p) {
	this->AST = p.AST;
}

// toString, returns a string representation of the program that is a valid postscript program
std::string Program::toString() {
	// TODO traverse AST
	return "newpath \n 0 0 5 0 360 arc closepath stroke showpage";
}

// interpret, takes a string of source code and converts it to postscript
void Program::interpret(std::string source) {
	// TODO build AST from source
}