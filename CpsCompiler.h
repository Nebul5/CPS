// ************************* //
//        CpsCompiler.h      //
//       by Jake Conner      //
// ************************* //

#ifndef CPSCOMPILER_H_INCLUDED
#define CPSCOMPILER_H_INCLUDED

#include <string>
// std::string
#include <utility>
// std::pair
#include <memory>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <math.h>
#include <fstream>
#include <iostream>


// ************************************* //
//           Mat4 and Vec4               //
//     for doing 3D transformations      //
//          by Jake Conner               //
// ************************************* //


// Vec4 holds a vector with 4 components
struct Vec4 {
	double x, y, z, w;
	Vec4() :x(0), y(0), z(0), w(1.0) {};
	Vec4(double X, double Y, double Z, double W) : x(X), y(Y), z(Z), w(W) {};

	// Vector addition
	Vec4 operator+(const Vec4 & r) {
		Vec4 newVec(x + r.x, y + r.y, z + r.z, 1.0);
		return newVec;
	}

	// Vector subtraction
	Vec4 operator-(const Vec4 & r) {
		Vec4 newVec(x - r.x, y - r.y, z - r.z, 1.0);
		return newVec;
	}

	// Dot product
	double dot(Vec4 v) {
		return x * v.x + y * v.y + z * v.z;
	}

	// this X v
	Vec4 cross(Vec4 v) {
		Vec4 newVec(y*v.z - z * v.y, z*v.x - x * v.z, x*v.y - y * v.x, 1.0);
		return newVec;
	}

	// makeUnit
	void makeUnit() {
		double m = sqrt(x*x + y * y + z * z);
		if (m > 1) {
			x /= m;
			y /= m;
			z /= m;
		}
	}

	// set fn
	void set(double X, double Y, double Z, double W) {
		x = X;
		y = Y;
		z = Z;
		w = W;
	}
};

// Mat4, holds a 4x4 matrix
struct Mat4 {
	std::vector<double> m;

	Mat4(std::vector<double> mat) : m(mat) {};

	double operator[](unsigned int index) const {
		return m[index];
	}

	double & operator[](unsigned int index) {
		return m[index];
	}

	Mat4 operator+(const Mat4 & mat) {
		Mat4 temp(m);
		for (auto i = 0; i < m.size(); i++) {
			temp[i] += mat[i];
		}
		return temp;
	}

	Vec4 operator*(Vec4 & v) {
		double x, y, z, w;
		x = v.x * m[0] + v.y * m[4] + v.z * m[8] + v.w * m[12];
		y = v.x * m[1] + v.y * m[5] + v.z * m[9] + v.w * m[13];
		z = v.x * m[2] + v.y * m[6] + v.z * m[10] + v.w * m[14];
		w = v.x * m[3] + v.y * m[7] + v.z * m[11] + v.w * m[15];

		Vec4 newVec(x, y, z, w);
		return newVec;
	}

	Mat4 transpose() {
		double newMat[16] = { m[0], m[4], m[8], m[12],
			m[1], m[5], m[9], m[13],
			m[2], m[6], m[10], m[14],
			m[3], m[7], m[11], m[15] };

		std::vector<double> newMatVec(newMat, newMat + 16);
		Mat4 trans(newMatVec);
		return trans;
	}
};

// makeIdentity
Mat4 makeIdentity();

// makeTranslation
Mat4 makeTranslation(double x, double y, double z);

// makeScale
Mat4 makeScale(double x, double y, double z);

// makeRotation
Mat4 makeRotation(double radians, double x, double y, double z);

// makePerspective
Mat4 makePerspective(double fieldOfView, double aspect, double near, double far);


// ************************************* //
//           END Mat4, Vec4              //
// ************************************* //

// Shape
struct Shape {
	std::string type;
	double x, y;
	double bound;
	double radius;
	std::vector<Vec4> points;

	virtual std::string draw(Mat4 transform) { return ""; }
};

// Polygon
struct Polygon : Shape {
	Polygon(int n, double len) {
		type = "Polygon";

		double PI = 3.14159;
		double theta = 2 * PI / n;
		radius = (PI - theta)*len / (2 * sin(theta));

		double firstAngle = (theta / 2) + (PI * 3/2 ); // Start here to make sure the first edge is || to the bottom bound
		Vec4 bottom1(radius*cos(firstAngle), radius*sin(firstAngle), 1.0, 1.0);
		Vec4 bottom2(radius*cos(firstAngle+theta), radius*sin(firstAngle+theta), 1.0, 1.0);
		points.push_back(bottom1);
		points.push_back(bottom2);

		for (auto i = 2; i < n; i++) {
			Vec4 newVec(radius*cos(firstAngle + (i*theta)), radius*sin(firstAngle + (i*theta)), 1.0, 1.0);
			points.push_back(newVec);
		}

		// Figure out distance to bound box edge from center
		bound = sin(firstAngle)*radius;
	}

	std::string draw(Mat4 transform) {
		Vec4 v = transform * points[0];
		std::string out = std::to_string(v.x) + " " + std::to_string(v.y) + " moveto ";
		for (auto i = 1; i < points.size(); i++) {
			v = transform * points[i];
			out += std::to_string(v.x);
			out += " ";
			out += std::to_string(v.y);
			out += " lineto ";
		}
		out += " closepath stroke ";
		return out;
	}
};

// Sphere, stores a 3-dimensional sphere with build in shading
struct Sphere : Shape {
	std::vector<Vec4> normals;
	Vec4 lightVec;
	Vec4 color;
	double radius;
	Sphere(double r, Vec4 c, Vec4 l) {
		type = "Sphere";
		color = c;
		lightVec = l;

		radius = r;
		double PI = 3.14159;
		int resolution = 32;
		int count = 0;
		int sliceRes = (2 * resolution);

		for (double phi = 0.0; phi < PI; phi+=(PI/resolution)) {
			double innerRadius1 = sin(phi)*radius;
			double innerRadius2 = sin(phi+(PI/resolution))*radius;
			for (double theta = 0.0; theta < (2 * PI); theta += ((2*PI) / sliceRes)) {
				double leftTheta = theta + (2 * PI / sliceRes);
				double lowerPhi = phi + (PI / resolution);

				Vec4 upperRing1(cos(theta)*innerRadius1, cos(phi)*radius, sin(theta)*innerRadius1, 1.0);
				Vec4 lowerRing1(cos(theta)*innerRadius2, cos(lowerPhi)*radius, sin(theta)*innerRadius2, 1.0);

				Vec4 upperRing2(cos(leftTheta)*innerRadius1, cos(phi)*radius, sin(leftTheta)*innerRadius1, 1.0);
				Vec4 lowerRing2(cos(leftTheta)*innerRadius2, cos(lowerPhi)*radius, sin(leftTheta)*innerRadius2, 1.0);

				points.push_back(upperRing1);
				points.push_back(lowerRing1);

				points.push_back(lowerRing2);
				points.push_back(upperRing2);

				int index = points.size() - 1;
				Vec4 a = upperRing1 - upperRing2;
				Vec4 b = upperRing1 - lowerRing1;

				Vec4 c = a.cross(b);
				normals.push_back(c);
			}
		}
	}

	// draw the sphere with the given transformations
	std::string draw(Mat4 transform) {
		Vec4 v = transform * points[0];
		std::string out = ""; // std::to_string(v.x) + " " + std::to_string(v.y) + " " + " moveto\n";
		int count = 0;
		int normalIndex = 0;
		std::string buffer = "";
		for (auto i = 0; i < points.size(); i+=4) {
			v = transform * points[i];
			buffer += std::to_string(v.x);
			buffer += " ";
			buffer += std::to_string(v.y);
			buffer += " moveto\n";

			v = transform * points[i+1];
			buffer += std::to_string(v.x);
			buffer += " ";
			buffer += std::to_string(v.y);
			buffer += " lineto\n";

			v = transform * points[i+2];
			buffer += std::to_string(v.x);
			buffer += " ";
			buffer += std::to_string(v.y);
			buffer += " lineto\n";

			v = transform * points[i+3];
			buffer += std::to_string(v.x);
			buffer += " ";
			buffer += std::to_string(v.y);
			buffer += " lineto\n";

			if (normals[normalIndex].z < 0) {
				buffer = "";
			}
			else {
				out += buffer;
				double xComp = normals[normalIndex].x;
				double yComp = normals[normalIndex].y;
				double zComp = normals[normalIndex].z;
				
				Vec4 UnitVec(xComp, yComp, zComp, 1.0);
				UnitVec.makeUnit();

				double lambCos = UnitVec.dot(lightVec);

				out += std::to_string(color.x + color.x*lambCos);
				out += " ";
				out += std::to_string(color.y + color.y*lambCos);
				out += " ";
				out += std::to_string(color.z + color.z*lambCos);
				out += " setrgbcolor ";
				out += " closepath ";
				out += " fill\n";

				out += buffer;
				out += " closepath ";
				out += " stroke\n";

				buffer = "";
			}
			normalIndex++;
		}
		return out;
	}
};

// Lexer stores source code as a sequence of strings delimited by whitespace
struct Lexer {
	std::vector<std::string> data;
	int index;

	Lexer() {
		index = 0;
	}

	Lexer(Lexer & l) {
		index = l.index;
		data = l.data;
	}

	void Lex(std::string source){
		std::stringstream s(source);
		std::string token;
		index = 0;
		while (s >> token) {
			data.push_back(token);
		}
	}

	void Lex(std::fstream & source) {
		std::string token;
		index = 0;
		while (source >> token) {
			data.push_back(token);
		}
	}

	void reset() {
		index = 0;
	}

	std::string next() {
		if (index == data.size()) {
			return "EOF";
		}
		else {
			return data[index++];
		}
	}

	// Look at the next value without incrementing
	std::string peek() {
		if (index == data.size()) {
			return "EOF";
		}
		else {
			return data[index+1];
		}
	}

	// Look at the next value without incrementing
	std::string peek(unsigned int offset) {
		if (index+offset >= data.size()) {
			return "EOF";
		}
		else {
			return data[index + offset];
		}
	}

	// Assumes the next value is a double
	double num() {
		std::string token = next();
		if (token == "EOF") {
			return 0.0;
		}
		else {
			return std::stod(token);
		}
	}
};

// Stores a postscript program whose source is a string written in standard C++
class Program {

private:
	Lexer Code;
	std::vector<std::string> Parsed;
	std::vector<Mat4> transformations;
	std::string Postscript;
	std::unordered_map<std::string, Shape*> Objects;
	double X, Y;

	// State handlers
	void parseShape();
	void parseVertical();
	void parseHorizontal();

	// interpret
	void interpret();

public:
  Program(std::string source);
  Program(const Program &p);

  std::string toString();

  void compile(std::string filename);
};

#endif
