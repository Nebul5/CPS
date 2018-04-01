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
	if (n % 2 == 1)
	{
		pair<int, int> box = bounding_Box(n, s);
		apothem = box.second / 2;
	}
	point.first = (int)(x - s / 2);
	point.second = (int)(y - apothem);

	return point;
}

int main()
{

	 box b;
	 box a = box(5, 3);
	 box c = box(10, 10);
	 box d = box(1, 25);
	 box g = box(11, 4);

	 pair<int,int> answer = b.maxD({ a,c,d,g });
	cout << a.getHeight() << "  " << a.getWidth() << endl;
	cout << answer.first << "\t" << answer.second << endl;
	/*
	for (int n = 3; n < 12; n++)
	{
		pair<int, int> bBox = bounding_Box(n, 100);
		cout <<"Sides " << n << " the Width is "<< bBox.first << " the Height is " << bBox.second << endl;
	}

	cout << " \n\n Starting Point \n\n ";
	for (int n = 3; n < 12; n++)
	{
		pair<float, float> bBox = starting_Point(300, 300, 100, n);
		cout << "Sides " << n << " the x Coord is " << bBox.first << " the y coord is " << bBox.second << endl;
	}
	*/
    return 0;
}

