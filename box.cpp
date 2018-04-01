#include "box.h"
#include<utility>
using std::pair;
box::box(int w, int h)
{
	width = w;
	height = h;
}
int	box::getHeight()
{
	return height;
}
int box::getWidth()
{
	return width;
}

int	box::getHeight() const
{
	return height;
}
int box::getWidth() const
{
	return width;
}

pair<int, int> box::maxD(const initializer_list<box> &list)
{
	pair<int, int> maxDimensions = std::make_pair(0, 0);
	for(auto &itm : list)
	{
		if (maxDimensions.first < itm.getWidth())
			maxDimensions.first = itm.getWidth();
		 if (maxDimensions.second < itm.getHeight())
			maxDimensions.second = itm.getHeight();
	}
	return maxDimensions ;
}
