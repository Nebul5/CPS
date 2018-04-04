

// takes the original bounding box for the unrotated shape and scales it to fit the rotated shape
//Only works for 90, 180 or 270 degree rotations
pair<int, int> Rotated::rotate_Box(pair<int,int> bBox, int degree, int n, double side)
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

//The New Starting point for rotated shapes so that the Shape remains centered on he current_point
pair<int, int> Rotated::start_Rotate_Poly(pair<int, int> current_point, pair<int, int> start_point, int degree, double side, int n)
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