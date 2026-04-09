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
void ADD();
void fileADD();
void Display(Node* current, int depth);
void Search();
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
void ADD(){

}

//file add
void fileADD(){

}

//display
void Display(Node* current, int depth){
  //empty
  if(!current){
    return;
  }
  //leaf
  else if(!(current->getR()) && !(current->getL())){
    return;
  }
  //right
  //center
  //left
}

//search
void Search(){

}
//remove

//quit
void Quit(){

}
