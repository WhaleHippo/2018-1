#include "HW1_Rectangle.h"
#define MIN(a, b) (a<b)? a:b
#define MAX(a, b) (a<b)? b:a
Rectangle::Rectangle() {
	xlow = 0;
	ylow = 0;
	width = 0;
	height = 0;
}

Rectangle::Rectangle(int x, int y, int w, int h) {
	xlow = x;
	ylow = y;
	width = w;
	height = h;
}

Rectangle::~Rectangle() {}

int Rectangle::getWidth() {
	return width;
}

int Rectangle::getHeight() {
	return height;
}

void Rectangle::setWidth(int w) {
	width = w;
}

void Rectangle::setHeight(int h) {
	height = h;
}

int Rectangle::operator==(const Rectangle &s)
{
	if (this == &s) return true;
	if ((xlow == s.xlow) && (ylow == s.ylow) && (width == s.width) && (height == s.height))
		return true;
	else
		return false;
}

Rectangle Rectangle::operator&(const Rectangle &r)
{
	int left1 = xlow;
	int bottom1 = ylow;
	int right1 = xlow + width;
	int top1 = ylow + height;


	int left2 = r.xlow;
	int bottom2 = r.ylow;
	int right2 = r.xlow + r.width;
	int top2 = r.ylow + r.height;
	
	
	//case5
	int tempLeft = MIN(left1,left2);
	int tempRight = MAX(right1, right2);
	int tempBottom = MIN(bottom1, bottom2);
	int tempTop = MAX(top1, top2);
	
	
	return Rectangle(tempLeft,tempBottom,tempRight-tempLeft,tempTop-tempBottom);
}
	
Rectangle Rectangle::operator|(const Rectangle &r)
{
	int left1 = xlow;
	int bottom1 = ylow;
	int right1 = xlow + width;
	int top1 = ylow + height;


	int left2 = r.xlow;
	int bottom2 = r.ylow;
	int right2 = r.xlow + r.width;
	int top2 = r.ylow + r.height;
	
	/*겹치지 못하는 경우
	case1 - 1의 왼쪽 모서리가 2의 오른쪽 모서리보다 오른쪽에 있음
	case2 - 1의 오른쪽 모서리가 2의 왼쪽 모서리보다 왼쪽에 있음
	case3 - 1의 위쪽 모서리가 2의 아래쪽 모서리보다 아래에 있음
	case4 - 1의 아래쪽 모서리가 2의 위쪽 모서리보다 위에 있음
	
	case5 - 겹침
	*/
	
	if(left1 > right2){ //case1
		return Rectangle();
	}
	else if(right1 < left2){ //case2
		return Rectangle();
	}
	else if(top1 < bottom2){ //case3
		return Rectangle();
	}
	else if(bottom1 > top2){ //case4
		return Rectangle();
	}
	
	//case5
	int tempLeft = MAX(left1,left2);
	int tempRight = MIN(right1, right2);
	int tempBottom = MAX(bottom1, bottom2);
	int tempTop = MIN(top1, top2);
	
	
	return Rectangle(tempLeft,tempBottom,tempRight-tempLeft,tempTop-tempBottom);
}

int Rectangle::operator-(const Rectangle &r)
{
	Rectangle temp = (*this)|r;
	
	
	return width*height - temp.width*temp.height;
}


int Rectangle::operator+(const Rectangle &r)
{
	Rectangle temp = (*this)|r;
	
	
	return width*height + r.width*r.height - temp.width*temp.height;
}



ostream& operator<< (ostream& os, const Rectangle& r) {
	os << "(" << r.xlow << "," << r.ylow << ")" << endl;
	os << "Area : " << r.width*r.height << endl;
	return os;
}


int main(){
	Rectangle a(0,1,4,3);
	Rectangle b(2,0,3,3);
	Rectangle c(a|b);
	cout << c << endl;
	return 0;
}
