// ************************* //
//       CpsCompiler.cpp     //
//       by Jake Conner      //
// ************************* //

#include "CpsCompiler.h"


// ************************************* //
//           Mat4 functions              //
//     for doing 3D transformations      //
//          by Jake Conner               //
// ************************************* //

// makeIdentity
Mat4 makeIdentity() {
	double newMat[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1 };

	std::vector<double> newMatVec(newMat, newMat + 16);
	Mat4 iden(newMatVec);
	return iden;
}

// makeTranslation
Mat4 makeTranslation(double x, double y, double z) {
	double newMat[16] = {
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		x, y, z, 1 };

	std::vector<double> newMatVec(newMat, newMat + 16);
	Mat4 trans(newMatVec);
	return trans;
}

// makeScale
Mat4 makeScale(double x, double y, double z) {
	double newMat[16] = {
		x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1 };

	std::vector<double> newMatVec(newMat, newMat + 16);
	Mat4 trans(newMatVec);
	return trans;
}

// makeRotation
Mat4 makeRotation(double radians, double x, double y, double z) {
	Vec4 unit(x, y, z, 1.0);
	unit.makeUnit();
	x = unit.x;
	y = unit.y;
	z = unit.z;
	double c = cos(radians);
	double s = sin(radians);

	double newMat[16] = {
		c + x * x*(1 - c), x*y*(1 - c) - z * s, x*z*(1 - c) + y * s, 0,
		y*x*(1 - c) + z * s, c + y * y*(1 - c), y*z*(1 - c) - x * s, 0,
		z*x*(1 - c) - y * s, z*y*(1 - c) + x * s, c + z * z*(1 - c), 0,
		0, 0, 0, 1 };

	std::vector<double> newMatVec(newMat, newMat + 16);
	Mat4 rot(newMatVec);
	return rot;
}

// makePerspective
Mat4 makePerspective(double fieldOfView, double aspect, double near, double far) {
	double f = tan(3.14159 * 0.5 - 0.5 * fieldOfView);
	double i = 1.0 / (near - far);

	double newMat[16] = {
		f / aspect, 0, 0, 0,
		0, f, 0, 0,
		0, 0, (near + far) * i, -1,
		0, 0, near * far * i * 2, 0 };

	std::vector<double> newMatVec(newMat, newMat + 16);
	Mat4 pers(newMatVec);
	return pers;
}



// ************************************* //
//         END Mat4 functions            //
// ************************************* //

// Visitor fns
std::string visitor::draw(Mat4 t, Polygon* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Circle* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Sphere* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Rectangle* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Spacer* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Layered* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Horizontal* p) {
	return p->DRAW(t);
}

std::string visitor::draw(Mat4 t, Vertical* p) {
	return p->DRAW(t);
}

std::string Polygon::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Circle::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Sphere::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Rectangle::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Spacer::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Layered::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Horizontal::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}

std::string Vertical::draw(Mat4 transform, class visitor &v) {
	return v.draw(transform, this);
}


// Draw function for Layered
std::string Layered::DRAW(Mat4 transform) {
	visitor drawVisitor;
	std::string out = "";
	for (auto i = 0; i < shapes.size(); i++) {
		out += shapes[i]->draw(transform, drawVisitor);
	}
	return out;
}


// Draw function for Horizontal
std::string Horizontal::DRAW(Mat4 transform) {
	visitor drawVisitor;
	std::string out = "";
	out += shapes[0]->draw(transform, drawVisitor);

	Mat4 move = transform * makeTranslation(shapes[0]->width, 0.0, 0.0);
	out += shapes[0]->draw(transform, drawVisitor);
	for (auto i = 1; i < shapes.size(); i++) {
		move = move * makeTranslation(shapes[i]->width, 0.0, 0.0);
		out += shapes[i]->draw(move, drawVisitor);
		move = move * makeTranslation(shapes[i]->width, 0.0, 0.0);
	}
	return out;
}

// Draw function for Vertical
std::string Vertical::DRAW(Mat4 transform) {
	visitor drawVisitor;
	std::string out = "";
	out += shapes[0]->draw(transform, drawVisitor);

	Mat4 move = transform * makeTranslation(0.0, shapes[0]->height, 0.0);
	out += shapes[0]->draw(transform, drawVisitor);
	for (auto i = 1; i < shapes.size(); i++) {
		move = move * makeTranslation(0.0, shapes[0]->height, 0.0);
		out += shapes[i]->draw(move, drawVisitor);
		move = move * makeTranslation(0.0, shapes[0]->height, 0.0);
	}
	return out;
}

// Program constructor, takes a string of source code
Program::Program(std::string source) { 
	if (source.find(".cps") == source.length() - 4) {
		std::fstream file;
		file.open(source, std::fstream::in);
		Code.Lex(file);
	}
	else {
		Code.Lex(source);
	}
	interpret();
}

// Copy ctr
Program::Program(const Program &p) { 
	this->Objects = p.Objects;
	this->Code = p.Code;
}

// toString, returns a string representation of the program that is a valid
// postscript program
std::string Program::toString() {
	return Postscript;
}

// compile
void Program::compile(std::string filename) {
	std::fstream file;
	file.open(filename + ".ps", std::fstream::out);
	file << toString();
}

// interpret, takes a string of source code and converts it to postscript
void Program::interpret() {
	transformations.push_back(makePerspective(40, 1, 0.0, 100));
	std::string token = Code.next();
	while(token!="EOF"){
		if (token == "draw") {
			token = Code.next();
			Mat4 t = makeIdentity();
			for (auto i = 0; i < transformations.size(); i++) {
				t = t * transformations[i];
			}
			Lexer shapeLex;
			shapeLex.Lex(Objects[token]->draw(t, drawVisitor));
			std::string term = shapeLex.next();
			while (term != "EOF") {
				Parsed.push_back(term);
				term = shapeLex.next();
			}
		}
		else if (token == "move") {
			double xTrans = Code.num();
			double yTrans = Code.num();
			transformations.push_back(makeTranslation(xTrans, yTrans, 0.0));
		}
		else if (token == "rotate") {
			double angle = Code.num() * (3.14159 / 180);
			double x = Code.num();
			double y = Code.num();
			double z = Code.num();
			transformations.push_back(makeRotation(angle, x, y, z));
		}
		else if (token == "scale") {
			double xScal = Code.num();
			double yScal = Code.num();
			transformations.push_back(makeScale(xScal, yScal, 1));
		}
		else if (token == "pop") {
			transformations.pop_back();
		}
		else if (token == "Circle") {
			token = Code.next();
			double arg1 = Code.num();
			Circle newCirc(arg1);
			Objects[token] = std::make_shared<Circle>(newCirc);
		}
		else if (token == "Rectangle") {
			token = Code.next();
			double arg1 = Code.num();
			double arg2 = Code.num();
			Rectangle newRect(arg1, arg2);
			Objects[token] = std::make_shared<Rectangle>(newRect);
		}
		else if (token == "Polygon") {
			token = Code.next();
			double arg1 = Code.num();
			double arg2 = Code.num();
			Polygon newPoly(arg1, arg2);
			Objects[token] = std::make_shared<Polygon>(newPoly);
		}
		else if (token == "Sphere") {
			token = Code.next();
			double radius = Code.num();
			double r = Code.num();
			double g = Code.num();
			double b = Code.num();
			double x = Code.num();
			double y = Code.num();
			double z = Code.num();
			Vec4 color(r, g, b, 1.0);
			Vec4 lightDir(x, y, z, 1.0);
			Sphere newSph(radius, color, lightDir);
			Objects[token] = std::make_shared<Sphere>(newSph);
		}
		else if (token == "Spacer") {
			token = Code.next();
			double arg1 = Code.num();
			double arg2 = Code.num();
			Spacer newSpace(arg1, arg2);
			Objects[token] = std::make_shared<Spacer>(newSpace);
		}
		else if (token == "Triangle") {
			token = Code.next();
			double arg1 = Code.num();
			Polygon newPoly(3, arg1);
			Objects[token] = std::make_shared<Polygon>(newPoly);
		}
		else if (token == "Square") {
			token = Code.next();
			double arg1 = Code.num();
			Polygon newPoly(4, arg1);
			Objects[token] = std::make_shared<Polygon>(newPoly);
		}
		else if (token == "Layered") {
			token = Code.next();
			std::string name = token;
			token = Code.next();
			std::vector<std::shared_ptr<Shape>> shapes;
			while (token != "end") {
				shapes.push_back(Objects[token]);
				token = Code.next();
			}
			Layered newLayer(shapes);
			Objects[name] = std::make_shared<Layered>(newLayer);
		}
		else if (token == "Horizontal") {
			token = Code.next();
			std::string name = token;
			token = Code.next();
			std::vector<std::shared_ptr<Shape>> shapes;
			while (token != "end") {
				shapes.push_back(Objects[token]);
				token = Code.next();
			}
			Horizontal newHoriz(shapes);
			Objects[name] = std::make_shared<Horizontal>(newHoriz);
		}
		else if (token == "Vertical") {
			token = Code.next();
			std::string name = token;
			token = Code.next();
			std::vector<std::shared_ptr<Shape>> shapes;
			while (token != "end") {
				shapes.push_back(Objects[token]);
				token = Code.next();
			}
			Vertical newVert(shapes);
			Objects[name] = std::make_shared<Vertical>(newVert);
		}
		token = Code.next();
	}

	Postscript = "newpath\n";
	for (auto i = 0; i < Parsed.size(); i++) {
		Postscript += (Parsed[i] + " ");
	}
	Postscript += "\nshowpage";
}

