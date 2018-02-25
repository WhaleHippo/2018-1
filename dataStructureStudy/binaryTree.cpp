#include <iostream>

using namespace std;
class node{
public:
  int data;
  node* parent;
  node* left;
  node* right;
  node(){
    parent = NULL;
    left = NULL;
    right = NULL;
  }
  node(int data){
    parent = NULL;
    this->data = data;
    left = NULL;
    right = NULL;
  }
  node(int data, node* pa){
    parent = pa;
    this->data = data;
    left = NULL;
    right = NULL;
  }
  ~node(){
    delete this->left;
    delete this->right;
  }
};

class binanryTree{
private:
  int size;
  node* root;

  void print(node* mid){
    if(mid != NULL){
      print(mid->left);
      cout << mid->data << endl;
      print(mid->right);
    }
  }

  void insert(node* mid, int value){
    if(mid->data < value){
      if(mid->right == NULL){
        mid->right = new node(value, mid);
      }
      else{
        insert(mid->right, value);
      }
    }
    else{
      if(mid->left == NULL){
        mid->left = new node(value, mid);
      }
      else{
        insert(mid->left, value);
      }
    }
  }


public:

  binanryTree(){
    size = 0;
    root = NULL;
  }
  ~binanryTree(){
    delete root;
  }

  binanryTree* insert(int value){
    if(root == NULL){
      root = new node(value);
      size++;
      return this;
    }
    insert(root, value);
    size++;
    return this;
  }

  binanryTree* printAll(){
    print(root);
    return this;
  }

  binanryTree* del(int index){
    /*
    index rule
    1. 0 == root
    2. left = i*2 + 1
    3. right = i*2 + 2
    */

    // get index's node
    node* state;
    if((state->left == NULL) && (state->right == NULL)){//case 1
      delete state;
    }
    else if((state->left == NULL) || (state->right == NULL)){//case 2
      if(state->left == NULL){
        delete state;
        state = state->right;
      }
      if(state->right == NULL){
        delete state;
        state = state->left;
      }
    }
    else{//case 3
    }

    size--;
  }

  node* search(int value){
    node* index;
    for(index = root; index != NULL; ){
      if(value > index->data){
        index = index->right;
      }
      else if(value < index->data){
        index = index->left;
      }
      else{
        return index;
      }
    }
    return NULL;
  }

};


int main(int argc, char const *argv[]) {
  binanryTree* a;


  a = new binanryTree();
  for(int i =0;i<17;i++){
    a->insert(i*i%17);
  }

  delete a;
  return 0;
}
