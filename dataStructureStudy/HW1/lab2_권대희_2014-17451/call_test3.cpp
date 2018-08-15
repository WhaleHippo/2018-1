#include <iostream>
using namespace std;
void swap3(int &a, int &b)
{
	cout << "Before : ";
	cout << a << "," << b << endl;
	int temp = a; a = b; b = temp;
	cout << "After : ";
	cout << a << "," << b << endl;
}
int main() {
	int n1 = 10, n2 = 20;
	cout << "Before swap3 : ";
	cout << n1 << "," << n2 << endl;
	swap3(n1, n2);
	cout << "After swap3 : ";
	cout << n1 << "," << n2 << endl;
}