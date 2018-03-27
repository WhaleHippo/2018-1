#include <iostream>
#include <string>
using namespace std;
class Array2D{
private:
	int** m_array;
	int m_size;
public:
	Array2D(int size){
		m_size = size;
		m_array = new int* [m_size];
		for(int i = 0; i < m_size; i++){
			m_array[i] = new int[m_size];
		}
		for(int i = 0; i < m_size; i++){
			for(int j = 0; j < m_size; j++){
				m_array[i][j] = m_size*i+j+1;
			}
		}
	}
	~Array2D(){
		for(int i = 0; i < m_size; i++){
			delete[] m_array[i];
		}
		delete[] m_array;
	}
	
	void Swap(int* a, int* b){
		int temp = *a;
		*a = *b;
		*b = temp;
	}
	
	friend ostream& operator<<(ostream& os, const Array2D& a) {
		for(int i = 0; i < a.m_size; i++){
			for(int j = 0; j < a.m_size; j++){
				os << a.m_array[i][j];
				os << "\t";
			}
			os<<endl;
		}
		return os;
	}
	
	void MirrorRight(){
		for(int i = 0; i < m_size; i++){
			for(int j = 0; j < m_size / 2; j++){
				Swap(&m_array[i][j], &m_array[i][m_size-j-1]);
			}
		}
	}
	void MirrorDown(){
		for(int i = 0; i < m_size / 2; i++){
			for(int j = 0; j < m_size; j++){
				Swap(&m_array[i][j], &m_array[m_size-i-1][j]);
			}
		}
	}
	void MirrorSE45(){
		for(int i = 0; i < m_size; i++){
			for(int j = 0; j < i; j++){
				Swap(&m_array[i][j], &m_array[j][i]);
			}
		}
	}
	void MirrorNE45(){
		MirrorSE45();
		MirrorDown();
		MirrorRight();
	}
};

int main() {
	Array2D a(6);

	cout << "<Original Matrix>" << endl;
	cout << a << endl;

	Array2D b(6);
	cout << "<After MirrorRight>" << endl;
	b.MirrorRight();
	cout << b << endl;

	Array2D c(6);
	cout << "<After MirrorDown>" << endl;
	c.MirrorDown();
	cout << c << endl;

	Array2D d(6);
	cout << "<After MirrorNE45>" << endl;
	d.MirrorNE45();
	cout << d << endl;

	Array2D e(6);
	cout << "<After MirrorSE45>" << endl;
	e.MirrorSE45();
	cout << e << endl;

	//system("pause");
	return 0;
}
