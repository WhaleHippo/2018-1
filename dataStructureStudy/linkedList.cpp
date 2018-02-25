#include <iostream>

using namespace std;
class node{
private:
public:
  int data;
  node* next;
  node* pre;
  node(){
    next = NULL;
    pre = NULL;
  }
  node(int data){
    this->data = data;
    next = NULL;
    pre = NULL;
  }

};

class linkedList{
private:
  int size;
  node* start;
  node* end;
public:
  linkedList(){
    size = 0;
    start = new node();
    end = new node();
    start->pre = start;

    end->next = end;
  }
  node* getNnode(int n){
    /*if(size < n){
      return end->pre;
    }*/
    node* index = start;
    for(int i = 0; i < n && index!=end->pre; i++){
      index = index->next;
    }

    return index;
  }

  linkedList* insert(int data){
    if(size == 0){
      node* insertNode = new node(data);
      start->next = insertNode;
      insertNode->pre = start;
      insertNode->next = end;
      end->pre = insertNode;
    }
    else{
      node* insertNode = new node(data);
      node* index = getNnode(size);
      node* indexNext = index->next;

      index->next = insertNode;
      indexNext->pre = insertNode;
      insertNode->next = indexNext;
      insertNode->pre = index;

    }
    size++;

    return this;
  }

  linkedList* insert(int data, int n){
    node* insertNode = new node(data);
    node* index = getNnode(n);
    node* indexNext = index->next;

    index->next = insertNode;
    indexNext->pre = insertNode;
    insertNode->next = indexNext;
    insertNode->pre = index;

    size++;

    return this;
  }

  linkedList* printAll(){
    node* index = start->next;
    for(; index!=end; index = index->next){
      cout << index->data <<" ";
    }
    cout << endl;

    index = end->pre;
    for(; index!=start; index = index->pre){
      cout << index->data <<" ";
    }
    cout << endl;
    return this;
  }



  linkedList* delNnode(int n){
    node* index = getNnode(n+1);
    index->pre->next = index->next;
    index->next->pre = index->pre;
    size--;
    delete index;

    return this;
  }

  linkedList* delnode(){
    delNnode(0); //del fist node
    //delNnode(size-1);//del last node

    return this;
  }

  ~linkedList(){
    while(size!=0){
      delnode();
    }

    delete start;
    delete end;
  }



};

int main(int argc, char const *argv[]) {
  linkedList a;
  for(int i =0;i<7;i++){
    a.insert(i);
  }
  a.printAll();
  a.insert(10,5);
  a.printAll();


  return 0;
}
