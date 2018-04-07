#include <iostream>
#include <string>
using namespace std;
class BigNum{
private:
	int* number;
	/*
		index0 === 1의 자리
		index1 === 10의 자리
	*/
	int size;//총 자리수
public:

	BigNum(){
		number = NULL;
		size = 0;
	}
	BigNum(string num){
		size = num.size();
		number = new int[size];
		for(int i =0; i < size; i++){
			number[i] = num[size -1 -i] - '0';
		}
	}
	BigNum(const BigNum& bignum){
		size = bignum.size;
		number = new int[size];
		int* tempNumber = bignum.number;
		for(int i = 0; i< size; i++){
			number[i] = tempNumber[i];
		}
	}
	
	~BigNum(){
		size = 0;
		delete[] number;
	}



	
	BigNum operator+(const BigNum& b) {
		int tempSize;
		string result = "";
		int c = 0; // carry
		char e[1]; // int to stirng
		
		if(size > b.size){
			for(int i = 0 ; i< b.size;i++){
				e[0] = ((number[i]+b.number[i]+c)%10) + '0';
				result.append(e);
				c = (number[i]+b.number[i]+c)/10;
			}
			for(int i = b.size ; i< size;i++){
				e[0] = ((number[i]+c)%10) + '0';
				result.append(e);
				c = (number[i]+c)/10;
			}
			if(c==1){
				result.append("1");
			}
		}
		else{

			for(int i = 0 ; i< size;i++){
				e[0] = ((number[i]+b.number[i]+c)%10) + '0';
				result.append(e);
				c = (number[i]+b.number[i]+c)/10;
			}
			for(int i = size ; i< b.size;i++){
				e[0] = ((b.number[i]+c)%10) + '0';
				result.append(e);
				c = (b.number[i]+c)/10;
			}
			if(c==1){
				result.append("1");
			}
		}
		
		
		//reverse string
		string temp(result);
		int stringSize = temp.size();
		for(int i = 0; i < stringSize; i++){
			result[i] = temp[stringSize - i -1];
		}
		
		return BigNum(result);
	}


	BigNum operator*(const int b) {
	
		BigNum result("0");
		for(int i = 0;i < b; i++){
			result = result + *this;
		}
		
		return result;

	}
	
	BigNum operator*(const BigNum& b) {
		BigNum* adds = new BigNum[b.size];
		
		BigNum result("0");
		for(int i = 0; i < b.size; i++){
			adds[i] =  (*this) * b.number[i];
		}
		
		for(int i = 1; i < b.size; i++){
			for(int j = i; j<b.size; j++){
				adds[j] = adds[j]*10;
			}
			
		}
		
		for(int i = 0; i < b.size; i++){
			result = result +adds[i];
		}
		
		delete[] adds;
		return result;
	}
	//*/
	
	void operator=(const BigNum& b) {
		size = b.size;
		delete[] number;
		number = new int[size];
		
		for(int i = 0; i < size; i++){
			number[i] = b.number[i];
		}
	}
	friend ostream& operator<<(ostream& os, const BigNum& a) {
		for(int i = 0; i < a.size; i++){
			os << a.number[a.size-1-i];
		}
		return os;
	}

};

int main(){

	BigNum a("1231546135315");
	BigNum b("2");
	BigNum c("1");
	

	cout << a*b*c << endl;

	return 0;
}
