#include <iostream>
using namespace std;
int main() {
	int a = 100;
	int b = 200;
	int* aPtr = &a;
	int* bPtr = &b;
	cout << a << "," << b << endl;
	cout << *aPtr << "," << *bPtr << endl;
	cout << aPtr << "," << bPtr << endl;
	*aPtr += 5;
	*bPtr += 5;
	cout << a << "," << b << endl;
	cout << *aPtr << "," << *bPtr << endl;
	a += 5;
	b += 5;
	cout << a << "," << b << endl;
	cout << *aPtr << "," << *bPtr << endl;
	return 0;
}