#include <iostream>
#include <string>
using namespace std;

int* String_To_Int(string As) {
	int* A = new int[As.size()];
	
	for (int i = As.size() - 1; i > -1; i--) {
		A[i] = As[As.size() -1 -i] - '0';
	}

	return A;
}

void CalculateSum(int* A, int A_size, int* B, int B_size) {
	int max_size = 0;
	if (A_size > B_size) {
		max_size = A_size+1;
	}
	else {
		max_size = B_size+1;
	}

	int* a = new int[max_size];
	int* b = new int[max_size];
	int* c = new int[max_size];

	for (int i = 0; i < max_size; i++) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
	}

	for (int i = 0; i < A_size; i++) {
		a[i] = A[i];
	}
	for (int i = 0; i < B_size; i++) {
		b[i] = B[i];
	}


	for (int i = 0; i < max_size - 1; i++) {
		c[i] = c[i]+b[i]+a[i];

		if (c[i] >= 10) {
			c[i] = c[i] % 10;
			c[i + 1] = 1;
		}
	}




	cout << "A + B : ";
	for (int i = max_size - 1; i > -1; i--) {
		if (i == max_size - 1 && c[i] == 0) {
			cout << "";
		}
		else {
			cout << c[i];
		}
	}

	delete[] a;
	delete[] b;
	delete[] c;

}

int main() {
	string As, Bs;
	int A_size, B_size;
	int *A, *B;
	cout << "Input number A : "; cin >> As;
	cout << "Input number B : "; cin >> Bs;
	A_size = As.size();
	B_size = Bs.size();



	A = String_To_Int(As);
	B = String_To_Int(Bs);


	CalculateSum(A, A_size, B, B_size);

	int asbcd;
	cin >> asbcd;

	delete[] A;
	delete[] B;
}
