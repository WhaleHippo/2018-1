#pragma once
#include<iostream>
using namespace std;
class Rectangle
{
private:
	int xlow, ylow, width, height;
public:
	Rectangle();
	Rectangle(int x, int y, int w, int h);
	~Rectangle();
	int getWidth();
	int getHeight();
	void setWidth(int w);
	void setHeight(int h);

	int operator==(const Rectangle&);
	friend ostream& operator<<(ostream&, const Rectangle&);

};