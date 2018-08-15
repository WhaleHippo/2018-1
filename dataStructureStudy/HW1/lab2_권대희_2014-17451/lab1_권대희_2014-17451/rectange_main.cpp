#include "rectangle.h"
using namespace std;
int main() {
	Rectangle a;
	Rectangle c(0, 0, 3, 4);

	cout << a;
	cout << c;
	cout << "a=c?" << (a == c) << endl;

	a.setWidth(3);
	a.setHeight(4);

	cout << a;
	cout << "a=c?" << (a == c) << endl;

	return 0;
}