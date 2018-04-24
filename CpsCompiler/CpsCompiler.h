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
#include <cmath>
#include <fstream>
#include <iostream>
#include <utility>
#include <algorithm>


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

	// cross product
	Vec4 cross(Vec4 v) {
		Vec4 newVec(y*v.z - z * v.y, z*v.x - x * v.z, x*v.y - y * v.x, 1.0);
		return newVec;
	}

	// makeUnit
	void makeUnit() {
		x *= 100;
		y *= 100;
		z *= 100;

		double m = sqrt(x*x + y * y + z * z);
		if (m > 1) {
			if (x != 0) {
				x /= m;
			}
			if (y != 0) {
				y /= m;
			}
			if (z != 0) {
				z /= m;
			}
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

	Mat4 operator*(Mat4 & v) {
		std::vector<double> newMatVec(16, 0.0);
		for (auto i = 0; i< 16; i += 4) {
			newMatVec[i+0] = v[i] * m[0] + v[i + 1] * m[4] + v[i + 2] * m[8] + v[i + 3] * m[12];
			newMatVec[i+1] = v[i] * m[1] + v[i + 1] * m[5] + v[i + 2] * m[9] + v[i + 3] * m[13];
			newMatVec[i+2] = v[i] * m[2] + v[i + 1] * m[6] + v[i + 2] * m[10] + v[i + 3] * m[14];
			newMatVec[i+3] = v[i] * m[3] + v[i + 1] * m[7] + v[i + 2] * m[11] + v[i + 3] * m[15];
		}

		Mat4 newMat(newMatVec);
		return newMat;
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
	double height; // From center
	double width; // From center
	double radius;
	std::vector<Vec4> points;

	virtual std::string DRAW(Mat4 transform) = 0;
	virtual std::string draw(Mat4 transform, class visitor &v) = 0;
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

		height = bottom1.y;
		width = bottom2.x;
		for (auto i = 2; i < n; i++) {
			Vec4 newVec(radius*cos(firstAngle + (i*theta)), radius*sin(firstAngle + (i*theta)), 1.0, 1.0);
			width = std::max(width, newVec.x);
			points.push_back(newVec);
		}
	}

	std::string DRAW(Mat4 transform) {
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

	std::string draw(Mat4 transform, class visitor &v);
};

// Circle
struct Circle : Shape {
	Circle(double r) {
		height = r;
		width = r;
	}

	std::string DRAW(Mat4 transform) {
		Vec4 start(width, 0.0, 0.0, 1.0);
		Vec4 c(0.0, 0.0, 0.0, 1.0);
		start = transform * start;
		c = transform * c;
		return std::to_string(c.x) + " " + std::to_string(c.y) + " " + std::to_string(start.x-c.x) + " 0 360 arc closepath stroke ";
	}

	std::string draw(Mat4 transform, class visitor &v);
};

// Rectangle
struct Rectangle : Shape {
	Rectangle(double w, double h) {
		height = h;
		width = w;

		Vec4 upperLeft(-width, height, 0.0, 1.0);
		Vec4 lowerLeft(-width, -height, 0.0, 1.0);
		Vec4 lowerRight(width, -height, 0.0, 1.0);
		Vec4 upperRight(width, height, 0.0, 1.0);

		points.push_back(upperLeft);
		points.push_back(lowerLeft);
		points.push_back(lowerRight);
		points.push_back(upperRight);
	}

	std::string DRAW(Mat4 transform) {
		Vec4 start(width, 0.0, 0.0, 1.0);
		Vec4 c(0.0, 0.0, 0.0, 1.0);
		start = transform * start;
		c = transform * c;

		auto v = transform * points[0];
		std::string out = std::to_string(v.x) +" " +std::to_string(v.y) +" moveto ";
		for (int i = 1; i < points.size(); i++) {
			auto v = transform * points[i];
			out += std::to_string(v.x);
			out += " ";
			out += std::to_string(v.y);
			out += " lineto ";
		}
		out += " closepath stroke ";

		return out;
	}

	std::string draw(Mat4 transform, class visitor &v);
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
		color.makeUnit();
		lightVec = l;
		lightVec.makeUnit();
		height = r;
		width = r;

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
				c.makeUnit();
				normals.push_back(c);
			}
		}
	}

	// draw the sphere with the given transformations
	std::string DRAW(Mat4 transform) {
		Vec4 v = transform * points[0];
		Vec4 lColor(1, 1, 1, 1);
		Vec4 camera(0, 0, 1, 1);
		double hardness = 0.4; // For specular

		std::string out = "";
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

			// Need the transformed normals in order to cull the right faces
			Vec4 normal = normals[normalIndex];
			Vec4 tNormal = transform * normal;

			if (tNormal.z < 0) {
				buffer = "";
			}
			else {
				out += buffer;
				double xComp = normal.x;
				double yComp = normal.y;
				double zComp = normal.z;
				
				Vec4 UnitVec(xComp, yComp, zComp, 1.0);
				UnitVec.makeUnit();

				// Do blinn-phong shading
				double camAngle = UnitVec.dot(camera);
				double lambCos = UnitVec.dot(lightVec);
				double diffAngle = lambCos - camAngle;
				diffAngle = sqrt(diffAngle*diffAngle);
				Vec4 specular(0, 0, 0, 1.0);
				Vec4 diffuse(1.0 + 1.0*lambCos, 1.0 + 1.0*lambCos, 1.0 + 1.0*lambCos, 1.0);
				
				if ( lambCos >= 0.0 ) {
					specular.x = ((lColor.x * diffAngle) - lColor.x)*hardness;
					specular.y = ((lColor.y * diffAngle) - lColor.y)*hardness;
					specular.z = ((lColor.z * diffAngle) - lColor.z)*hardness;

					if (specular.x < 0.0) {
						specular.x = 0.0;
					}
					if (specular.y < 0.0) {
						specular.y = 0.0;
					}
					if (specular.z < 0.0) {
						specular.z = 0.0;
					}
				}

				Vec4 finalColor(diffuse.x*color.x + specular.x, diffuse.y*color.y + specular.y, diffuse.z*color.z + specular.z, 1.0);

				out += std::to_string(finalColor.x);
				out += " ";
				out += std::to_string(finalColor.y);
				out += " ";
				out += std::to_string(finalColor.z);
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
		out += " 0 0 0 setrgbcolor ";
		return out;
	}

	std::string draw(Mat4 transform, class visitor &v);
};

// visitor
class visitor {
public:
	virtual std::string draw(Mat4 t, Polygon* p);
	virtual std::string draw(Mat4 t, Sphere* p);
	virtual std::string draw(Mat4 t, Circle* p);
	virtual std::string draw(Mat4 t, Rectangle* p);
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

	// Lex a string
	void Lex(std::string source){
		std::stringstream s(source);
		std::string token;
		index = 0;
		while (s >> token) {
			data.push_back(token);
		}
	}

	// Lex a file
	void Lex(std::fstream & source) {
		std::string token;
		index = 0;
		while (source >> token) {
			data.push_back(token);
		}
	}

	// Reset the index
	void reset() {
		index = 0;
	}

	// Return the current lexeme and increment the index
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
	std::unordered_map<std::string, std::shared_ptr<Shape>> Objects;
	double X, Y;

	// interpret
	void interpret();

	visitor drawVisitor;

public:
  Program(std::string source);
  Program(const Program &p);

  std::string toString();

  void compile(std::string filename);
};

#endif
