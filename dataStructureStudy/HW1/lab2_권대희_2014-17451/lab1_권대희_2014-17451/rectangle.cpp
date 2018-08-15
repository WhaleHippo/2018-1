#include "rectangle.h"
Rectangle::Rectangle() {
	this->xlow = 0;
	this->ylow = 0;
	this->width = 0;
	this->height = 0;
}

Rectangle::Rectangle(int x, int y, int w, int h) {
	this->xlow = x;
	this->ylow = y;
	this->width = w;
	this->height = h;
}

Rectangle::~Rectangle() {}
int Rectangle::getWidth(){
	return width;
}
int Rectangle::getHeight() {
	return height;
}

void Rectangle::setWidth(int w) {
	this->width = w;
}
void Rectangle::setHeight(int h) {
	this->height = h;
}

int Rectangle::operator==(const Rectangle &s) {
	if (this == &s) return true;
	if ((xlow == s.xlow) && (ylow == s.ylow) && (width == s.width) && (height == s.height)){
		return true;
	}
	else return false;
}

ostream& operator << (ostream& os, const Rectangle& r) {
	os << "c" << r.xlow << ", " << r.ylow << ")" << endl <<
		"Area : " << r.width*r.height << endl;
	return os;
}