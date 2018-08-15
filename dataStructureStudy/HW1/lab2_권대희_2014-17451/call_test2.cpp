#include "rectangle.h"
#include <iostream>
using namespace std;
int main() {
	Rectangle rectangle[3];
	rectangle[1].setWidth(2);
	rectangle[1].setHeight(3);
	(*(rectangle + 2)).setWidth(5);
	(*(rectangle + 2)).setHeight(7);
	cout << rectangle << endl;
	cout << rectangle[0];
	cout << rectangle[1];
	cout << rectangle[2];
	return 0;
}