#include <iostream>

using namespace std;

class heap{ // min heap
private:
  int* data;
  int size;
  int index;
public:
  heap(){
    size = 2;
    index = 0;
    data = new int[size];
  }
  ~heap(){
    delete[] data;
  }

  heap* insert(int a){
    if(index == size){
      cout << "size double"<<endl;
      size = size * 2;
      int* newData = new int[size];
      for(int i = 0; i < size/2;i++){
        newData[i] = data[i];
      }
      delete[] data;
      data = newData;
    }
    data[index++] = a;
    //re balanc
    int i = index - 1;
    while(i!=0){
      if(data[i] < data[(i-1)/2]){
        int temp = data[i];
        data[i] = data[(i-1)/2];
        data[(i-1)/2] = temp;
        i = (i-1)/2;
      }
      else{
        i = 0;
      }
    }
    return this;
  }

  heap* printAll(){
    for(int i = 0; i < index; i++){
      cout << i << " : " <<data[i] << endl;
    }
    return this;
  }

  heap* del(){
    if(this->index == 0) return this;
    index--;
    cout << data[0] << endl;
    data[0] = data[index];

    for(int i = 0; i < index/2; ){
      if(data[i*2+1] > data[i*2+2]){
        if(data[i] > data[i*2+2]){
          int temp = data[i];
          data[i] = data[i*2+2];
          data[i*2+2] = temp;
          i = i*2+2;
        }
        else{
          i = index;
        }
      }
      else{
        if(data[i] > data[i*2+1]){
          int temp = data[i];
          data[i] = data[i*2+1];
          data[i*2+1] = temp;
          i = i*2+1;
        }
        else{
          i = index;
        }
      }
    }

    return this;
  }
};

int main(int argc, char const *argv[]) {
  heap* a;
  a = new heap();
  for(int i = 0; i < 50;i++){
    a->insert((i*3)%17);
  }

  for(int i = 0; i < 50;i++){
    a->del();
  }
  delete a;
  return 0;
}
