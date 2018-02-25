#include <iostream>

using namespace std;

class AVLtree{
private:
  int* data;
  int size;
  int index;
public:
  AVLtree(){
    cout << "hippo" << endl;
    size = 2;
    index = 0;
    data = new int[size];
  }
  ~AVLtree(){
    cout << "bang" << endl;
    delete[] data;
  }

  AVLtree* insert(int a){
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
    return this;
  }

  AVLtree* printAll(){
    for(int i =0; i < index; i++){
      cout << data[i] << endl;
    }
    return this;
  }

};

int main(int argc, char const *argv[]) {
  AVLtree* a;
  a = new AVLtree();
  a->insert(0)->insert(1)->insert(2)->insert(3)->insert(4)->insert(5)->printAll();
  delete a;
  return 0;
}
