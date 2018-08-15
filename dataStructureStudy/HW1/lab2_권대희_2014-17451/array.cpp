#include <iostream>
using namespace std;
int main()
{
	int ia1[3];
	int *ia2 = new int[2];
	ia1[0] = 9; ia1[1] = -7; ia1[2] = 2;
	ia2[0] = -1; ia2[1] = 13;
	cout << ia1 << endl;
	cout << ia1[0] << ia1[1] << ia1[2] << endl;
	cout << *ia1 << *(ia1 + 1) << *(ia1 + 2) << endl;
	cout << ia1[0] + ia1[1] + ia1[2] << endl;
	cout << ia2 << endl;
	cout << ia2[0] << ia2[1] << endl;
	cout << *ia2 << *(ia2 + 1) << endl;
	cout << ia2[0] * ia2[1] << endl;
	return 0;
}