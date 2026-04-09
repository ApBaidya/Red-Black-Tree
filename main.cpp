/*
Aparajita Baidya 4.8.2026
Red Black Tree

Insertion due 4.24
-add one number or file input --> update tree
-print

Deletion due 5.15
-search
-remove --> update tree
*/

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Node.h"

using namespace std;

//function defs
Node* ADD(Node* current, int data);
void fileADD(Node* & root);
void Display(Node* current, int depth);
void Search(Node* current, int data);
void Remove();
void Quit();

int main(){
  //some variables
  char input[2];//user input
  int running = 1;
  //root
  Node* root = nullptr;
  while(running){
    cout<<"[a] add one number, [f] file add, [d] display, [s] search, [r] remove, [q] quit"<<endl;
    cin>>input;
    cin.ignore(10, '\n');
    cin.clear();
    if(strcmp(input,"a")==0){
      //single input
      cout<<"done"<<endl;
    }
    if(strcmp(input,"f")==0){
      //file
      cout<<"done"<<endl;
    }
    if(strcmp(input,"d")==0){
      //display
      cout<<"done"<<endl;
    }
    if(strcmp(input,"s")==0){
      //search
      cout<<"done"<<endl;
    }
    if(strcmp(input,"r")==0){
      //remove
      cout<<"done"<<endl;
    }
    if(strcmp(input,"q")==0){
      //quit
      running = 0;
    }
  }
  cout<<"Bye!"<<endl;
  return 0;
}

//add
Node* ADD(Node* current, int data){
  return current;
}

//file add
void fileADD(Node* & root){
  string inputF;//file name store in string
  int data;
  cout<<"file name please"<<endl;
  cin>>inputF;
  cin.clear();
  ifstream f(inputF);
  if(f){
    while(f>>data){
      root = ADD(root, data);//yes. i do want to do this. I think.
    }
  }
}

//display
void Display(Node* current, int depth){
  //empty
  if(!current){
    return;
  }
  //leaf
  else if(!(current->getR()) && !(current->getL())){
    for(int i = 0; i < depth; i++){
      cout<<"\t";
    }
    cout<<current->getC()<<" "<<current->getD()<<endl;
    return;
  }
  else{
    //right
    Display(current->getR(), depth+1);
    //center
    for(int i = 0; i < depth; i++){
      cout<<"\t";
    }
    cout<<current->getC()<<" "<<current->getD()<<endl;
    //left
    Display(current->getL(), depth+1);
  }
  return;
}

//search
void Search(Node* current, int data){
  //well, this is just a binary search tree...
  //end
  if(!current){
    cout<<"このNUMBER がありません。";
    return;
  }
  else if(current->getD() == data){
    cout<<current->getD()<<" "<<"exists"<<endl;
    return;
  }
  else if(data >= current->getD()){//right
    if(current->getR()!=NULL){
      Search(current->getR(), data);
      return;
    }
    cout<<"no"<<endl;
    return;
  }
  else if(data < current->getD()){//left
    if(current->getL()!=NULL){
      Search(current->getL(), data);
      return;
    }
    cout<<"NO"<<endl;
    return;
  }
  else{
    cout<<"this shouldn't happen."<<endl;
    return;
  }
}
//remove

//quit --> delete nodes like any other binary tree
void Quit(){

}
