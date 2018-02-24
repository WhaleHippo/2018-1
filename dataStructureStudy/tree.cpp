#include <iostream>

using namespace std;

class tree{
private:
  int* data;
  int size;
  int index;
public:
  tree(){
    cout << "hippo" << endl;
    size = 2;
    index = 0;
    data = new int[size];
  }
  ~tree(){
    cout << "bang" << endl;
    delete[] data;
  }

  tree* insert(int a){
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

  tree* printAll(){
    for(int i =0; i < index; i++){
      cout << data[i] << endl;
    }
    return this;
  }

};

int main(int argc, char const *argv[]) {
  tree* a;
  a = new tree();
  a->insert(0)->insert(1)->insert(2)->insert(3)->insert(4)->insert(5)->printAll();
  delete a;
  return 0;
}
