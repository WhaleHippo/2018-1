#include ¡°rectangle.h"
int main() {
	Rectangle a;
	Rectangle *b = new Rectangle();
	Rectangle c(1, 2, 3, 4);
	cout << a;
	cout << *b;
	cout << c;
	cout << "a = b ? " << (a == *b) << endl;
	a.setHeight(4);
	a.setWidth(3);
	cout << a;
	cout << "a = c ? " << (a == c) << endl;
	delete b;
	return 0;
}