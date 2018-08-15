#include <iostream>
using namespace std;
class Complex {
private:
	int real;
	int image;
public:
	Complex() : real(0), image(0) {
	}
	Complex(int r, int i) : real(r), image(i) {
	}
	~Complex() {};

	Complex operator+(const Complex& b) {
		return Complex(this->real + b.real, this->image + b.image);
	}

	Complex operator-(const Complex& b) {
		return Complex(this->real - b.real, this->image - b.image);
	}

	friend Complex operator*(const Complex& a, const Complex& b) {
		return Complex(a.real * b.real - a.image * b.image, a.real * b.image + a.image * b.real);
	}

	friend ostream& operator<<(ostream& os, const Complex& a) {
		os << "(" << a.real << " + "<<a.image<<"i)"<<endl;
		return os;
	}
};

int main() {
	Complex a;
	Complex b(5,3);
	Complex c(2,1);
	cout << a << b << c;

	cout << a + b + c << a - b + c << b - a + c;
	cout << a * b << b * c;

	return 0;
}