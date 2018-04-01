#pragma once
#include<initializer_list>
using std::initializer_list;
#include<utility>
using std::pair;
class box {
private:
	int height;
	int width;

public:
	box() = default;
	box(int w, int h);
int	getHeight();
int getWidth();

int	getHeight()const;
int getWidth()const;
pair<int,int> maxD(const initializer_list<box> & list);


};