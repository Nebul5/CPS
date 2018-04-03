// apothemCalc.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<math.h>
#include<utility>
#include<iostream>
#include"box.h"
using std::pair;
using std::make_pair;
using std::cout;
using std::endl;
//Find the Starting position based on the number of sides (n), side length (s) and centerpoint (pair<int, int>)
std::pair<int, int> bounding_Box(int n, float s) {
	float pi = 3.14159265;
	float height;
	float width;

	if (n % 2 == 1) {
		height = s*(1 + cos(pi / n)) / (2 * sin(pi / n));
		width = s* sin(pi * (n - 1) / (2 * n)) / sin(pi / n);
	}

	else if(n % 2 == 0 && n % 4 != 0) {
		height = s* cos(pi / n) / sin(pi / n);
		width = s / sin(pi / n);
	}

	else {
		height = s* cos(pi / n) / sin(pi / n);
		width = s* cos(pi / n) / sin(pi / n);
	}
	pair<int, int> Box = make_pair(width, height);

	return Box;
}


std::pair<int, int> starting_Point(float x, float y, float s, int n) {  //Default position is to have a flat side centered around the vertical axis of the center point
	pair<int, int> point;
	float pi = 3.14159265;
	float apothem = (s / 2) / tan(pi / n);
	point.first = (int)(x - s / 2);
	point.second = (int)(y - apothem);

	return point;
}
// takes the original bounding box for the unrotated shape and scales it to fit the rotated shape
//Only works for 90, 180 or 270 degree rotations
pair<int, int> rotate_Box(pair<int,int> bBox, int degree, int n, double side)
{

	if (degree == 90 || degree == 270)
	{
		int temp = bBox.first;
		bBox.first = bBox.second;
		bBox.second = temp;
		return bBox;
	}
	else
		return bBox;
}
	/*
	float pi = 3.14159265;
	int d = degree % (360 / n);
	double radian = (d / 180.0) * 3.1415;
	float apothem = (side / 2) / tan(pi / n);
	int w = bBox.first;
	int h = bBox.second;
	double r = side / 2 / sin(3.14 / n); // polygon radius

	int width = 0;
	int height = 0;

	if (n % 2 == 0 && n %4 != 0)
	{

	

	//double diam = sqrt(h*h + side*side);
	//double radius = diam / 2 - h / 2;

	double amplitude = w - h ;
	double frequency = pi*n / 360.0*d;
	height = h + amplitude*sin(frequency);
	width = h + amplitude * cos(frequency);
	//  height = (int)(r*sin(2*3.14/(2*n)*radian) + h);
	//  width = (int)(r*sin(2 * 3.14 / (2 * n)*radian) + w);
	}
	else if (n % 2 == 0) { //square style
		double amplitude = r - apothem;
		double frequency = pi*n / 360.0*d;
		height = h + amplitude * 2 * sin(frequency);
		width = height;
	}

	else { //odd
		/*
		radian = (360.0 / n) / 180.0 * 3.14;
		r = sqrt((side*side)/(2-2*cos(radian)));
		 height = 2 * (int)r;
		width = 2 * (int)r;
		
		double amplitude = w - h;
		double frequency = pi*4*n / 360.0*d;
		height = h + amplitude  * sin(frequency);
		width = h + amplitude  * cos(frequency);
		*/
	


//The New Starting point for rotated shapes so that the Shape remains centered on he current_point
pair<int, int> start_Rotate(pair<int, int> current_point, pair<int, int> start_point, int degree, double side, int n)
{
	
	int d = degree % (360 / n);
	
	double radian = (d / 180.0) * 3.1415;
	double r = side / 2 / sin(3.14 / n); // polygon radius
	pair<int, int> new_coord = std::make_pair(0, 0);

	int xs = start_point.first;
	int ys = start_point.second;

	int x = current_point.first;
	int y = current_point.second;

	xs = xs - x;
	ys = ys - y;

	double x2 = xs * cos(radian) - ys * sin(radian);
	double y2 = xs * sin(radian) + ys*cos(radian);

	new_coord.first = x + (int)(x2);
	new_coord.second = y + (int)y2;
	return new_coord;
}


int main()
{

	 box b;
	 box a = box(5, 3);
	 box c = box(100, 100);
	 box d = box(1, 25);
	 box g = box(11, 4);

	// pair<int,int> answer = b.maxD({ a,c,d,g });
	 int degree = 30;
	 pair<int, int> current = std::make_pair(300, 300);

	

	 double h = c.getHeight();
	 double w = c.getWidth();
	 double diam = sqrt(h*h + w*w);
	 double radian = degree * 3.14159 / 180;
	 double side = 100;
	
	 cout << " Bounding Box with no Rotation \n";
	 for (int n = 3; n < 12; n++)
	 {
		 pair<int, int> bBox = bounding_Box(n, 100);
		 cout << "Sides " << n << " the Width is " << bBox.first << " the Height is " << bBox.second << endl;
	 }

	 cout << " Starting Point with no Rotation \n";
	 for (int n = 3; n < 12; n++)
	 {
		 pair<int, int> bBox = starting_Point(current.first, current.second, 100, n);
		 cout << "Sides " << n << " X coord is " << bBox.first << " y coord is " << bBox.second << endl;
	 }

	cout<< "\n Bounding box with Rotation \n";

	for (int n = 3; n < 12; n++)
	{
		pair<int, int> bBox = bounding_Box(n, 100);
		pair<int, int> bBoxr = rotate_Box(bBox, degree, n, side);
		cout <<"Sides " << n << " the Width is "<< bBoxr.first << " the Height is " << bBoxr.second << endl;
	}
	
	cout << " \n Starting Point with Rotation \n ";
	for (int n = 3; n < 12; n++)
	{
		pair<float, float> bBox = bounding_Box(n, 100);
	//	cout << "Sides " << n << " the x Coord is " << bBox.first << " the y coord is " << bBox.second << endl;
		auto start = starting_Point(300, 300, 100, n);
		auto check = start_Rotate(current, start, degree, side, n);
			cout << "Sides " << n << " the x Coord is " << check.first << " the y coord is " << check.second << endl;
	}
	
    return 0;
}

