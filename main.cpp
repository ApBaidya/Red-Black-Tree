/*
Aparajita Baidya 4.16.2026
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
void leftRot(Node* & current);
void rightRot(Node* & root, Node* & current);
void Fix(Node* & root, Node* & current);
void ADD(Node* & root, Node* & parent, Node* & current, int data);
void fileADD(Node* & root);
void Display(Node* current, int depth);
void Search(Node* current, int data);
void Remove();
void Quit(Node* & current);

int main(){
  //some variables
  char input[2];//user input
  int running = 1;
  //root
  Node* root = NULL;
  int data;//user input data
  while(running){
    cout<<"[a] add one number, [f] file add, [d] display, [s] search, [r] remove, [q] quit"<<endl;
    cin>>input;
    cin.ignore(10, '\n');
    cin.clear();
    if(strcmp(input,"a")==0){
      //single input
      cout<<"gimme that value"<<endl;
      cin>>data;
      cin.clear();
      Node* tPar = NULL;
      ADD(root, tPar, root, data);
      cout<<root->getD();
      cout<<"done"<<root->getP()<<endl;
      if(root->getP()!= NULL){
	cout<<root->getP()->getD()<<root->getP()->getL()->getD()<<root->getL()<<endl;
      }
    }
    if(strcmp(input,"f")==0){
      //file
      cout<<"done"<<endl;
    }
    if(strcmp(input,"d")==0){
      //display
      Display(root, 0);
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
      Quit(root);
      Display(root, 0);
      running = 0;
    }
  }
  cout<<"Bye!"<<endl;
  return 0;
}

void leftRot(Node* & current){
  cout<<"left time"<<endl;
  /*
  Node* parent = NULL;
  parent = current->getP();
  Node* leftSub = NULL;
  Node* grandP = NULL;
  if(current->getL() != NULL){//left subtree???!!!
    cout<<"l1"<<endl;
    leftSub = current->getL();
    current->setL(NULL);
    current->setP(NULL);//break it off, current has no parent
    parent->setR(NULL);
    leftSub->setP(parent);
    parent->setR(leftSub);//make parent the parent of left subtree
  }
  if(parent->getP() == NULL){//if parent of parent is null
    cout<<"l2"<<endl;
    parent->setP(current);//current becomes root
    current->setL(parent);
    current->setP(NULL);//well, parent is now root
  }
  else if(parent->getD()<parent->getP()->getD()){//parent is left child of grandparent
    cout<<"l3"<<endl;
    grandP = parent->getP();
    grandP->setL(NULL);//break parent off for j o y 
    grandP->setL(current);//make grandP and current parent and child but LEFT
    current->setP(grandP);
  }
  else{
    cout<<"l4"<<endl;
    grandP = parent->getP();//make grandP and current parent and child but RIGHT
    grandP->setR(NULL);
    grandP->setR(current);
    current->setP(grandP);
  }
  cout<<"l5"<<endl;
  current->setL(parent);//make current and parent parent and child
  parent->setP(current);
  return current;*/
  //return current;
}

void rightRot(Node* & root, Node* & current){
  Node* parent = NULL;
  cout<<"RIGHT"<<endl;
  cout<<"find parent"<<endl;
  cout<<"current data"<<current->getD()<<endl;
  parent = current->getP();
  cout<<"parent"<<parent<<endl;
  cout<<"got Parent"<<endl;
  cout<<"Right time"<<endl;
  if(parent == NULL){//if we're rotating the root
    cout<<"rt root"<<endl;
    cout<<current->getD();
    Node* child = NULL;
    child = current -> getL();//get the child of current which will become root
    child->setP(NULL);
    current->setL(NULL);//safety
    Node* rsub = NULL;//in case, probbaly no need
    rsub = child->getR();
    current->setL(rsub);//again, just in case something strange occurs
    current->setP(child);
    child->setR(current);//now move current
    cout<<"Ha"<<endl;
    cout<<current->getP()->getD()<<endl;
    cout<<"pppp"<<endl;
    cout<<current->getP()->getL()<<endl;
    root = current->getP();//set root
    return;
  }
  Node* rightSub = NULL;//if child has a right tree
  Node* grandP = NULL;//not sure why this is needed
  Node* child = NULL;//child pointer
  child = current->getL();
  if(child!=NULL){//this...should always be true????????
    rightSub = child->getR();
  }
  child->setR(NULL);
  child->setP(NULL);
  current->setP(NULL);
  current->setL(NULL);
  if(current->getD() >= parent->getD()){//right child of parent
    cout<<"R1"<<endl;
    parent->setR(NULL);
    child->setP(parent);
    parent->setR(child);
    child->setR(current);//set current as child of child
    current->setP(child);
    current->setL(rightSub);//set right tree, can be null
  }
  else{//left child of parent
    cout<<"R2"<<endl;
    parent->setL(NULL);
    parent->setL(child);
    child->setP(parent);
    child->setR(current);//set current as child of child
    current->setP(child);
    current->setL(rightSub);//set right tree, can be null
  }
  if(rightSub!=NULL){
    rightSub->setP(current);
  }
  /*
  if(child->getR()!=NULL){//UWAAAA right subtree time
    cout<<"r1"<<endl;
    //rightSub = current->getR();//get right sub
    current->setR(NULL);
    current->setP(NULL);
    parent->setL(rightSub);
    rightSub->setP(parent);
    }*/ 
  //not dealing with root
  //what to consider
  //if 
  /*
  if(parent->getP()==NULL){
    cout<<"r2"<<endl;
    
    /*
    //parent->setP(NULL);
    current->setP(NULL);
    c = current->getL();
    c->setP(NULL);
    c->setP(parent);
    parent->setL(c);
    current->setP(c);
    //rightSub = c->getR();
    //c->setR(NULL);
    //current->setL(rightSub);
    rightSub->setP(NULL);
    rightSub->setP(current);
    cout<<"dddddd"<<endl;
    c->setR(current);
    //parent->setP(current);
    //current->setP(NULL);
    //current->setR(parent);
  }
  else if(parent->getD() >= parent->getP()->getD()){//if parent is the right child of grandP, make current right child of grandP
    cout<<"r3"<<endl;
    grandP = parent->getP();//get grandparent
    grandP->setR(NULL);
    grandP->setR(current);
    current->setP(grandP);
  }
  else{//make current the child of grandP
    cout<<"r4"<<endl;
    grandP = parent->getP();
    parent->setP(NULL);
    current->setP(grandP);
    grandP->setL(current);
  }
  cout<<"r5"<<endl;
  //current->setR(parent);//set parent child relationship between current and parent
  //parent->setP(current);
  //return current;*/
}

void Fix(Node* & root, Node* & current){
  cout<<"entered fix"<<endl;;
  Node* parent = NULL;
  cout<<1<<endl;
  parent = current->getP();
  cout<<2<<endl;
  if(parent == NULL){
    cout<<"hello, root"<<endl;
    return;
    //return current;
  }
  Node* grandP = NULL;
  grandP = parent->getP();
  //if parent of current is red
  if(parent -> getC() == "red"){
    cout<<"a"<<endl;
    //if parent is the left child of it's own parent
    if(parent->getD() < grandP->getD()){
      cout<<"a1"<<endl;
      //case 1: right child of grandparent is red
      if(grandP->getR()!=NULL){
	cout<<"a2"<<endl;
	if(grandP->getR()->getC() == "red"){
	  cout<<"a3"<<endl;
	  //set both children to black and grandP to red
	  parent->setC("black");
	  grandP->getR()->setC("black");
	  grandP->setC("red");
	  cout<<grandP->getC()<<endl;
	}
      }//end case 1
      //case 2 uncle is black now t r i a n g l e
      else if(current->getD()>=parent->getD()){//current is right child of parent
	cout<<"a4"<<endl;
	current = parent;
	//we're gonna take a look at parent
	leftRot(current);
      }
      //case 3 black uncle l i n e
      else{
	cout<<"a5"<<endl;
	parent->setC("black");
	grandP->setC("red");
	rightRot(root, grandP);
	cout<<grandP->getP()<<endl;
	//return;// grandP;
      }
    }
    //else
    else{
      cout<<"b"<<endl;
      if(grandP->getL() != NULL){//if grandP's left child is red
	cout<<"b1"<<endl;
	if(grandP->getL()->getC() == "red"){
	  cout<<"b2"<<endl;
	  grandP->setC("red");
	  grandP->getL()->setC("black");
	  parent->setC("black");
	}
      }
      //else current is left child of parent
      else if(current->getD()<parent->getD()){
	cout<<"b3"<<endl;
	current = parent;
	//rightRot(current);
	current->setC("black");
	grandP->setC("red");
	leftRot(grandP);
      }
      //WHAT IF CURRENT IS RIGHT CHILD OF PARENT*/
    }
  }
  //set Root to black
  Node* c = NULL;
  Node* p = NULL;
  c = current;
  p = c->getP();
  while(p!=NULL){//go up till c = root
    c = p;
    p = c -> getP();
  }
  c->setC("black");
  //return current;
}

//add...lets try this without passing by reference for once...
void ADD(Node* & root, Node* & parent, Node* & current, int data){
  if(!current){//found where to add. balance later
    current = new Node();
    current -> setD(data);
    if(!parent){
      current -> setC("black");
    }
    else{
      current -> setC("red");
    }
    current->setP(parent);
    cout<<"Parent"<<parent<<endl;
    if(parent!=NULL){
      if(current->getD()<parent->getD()){
	parent->setL(current);
      }
      else{
	parent->setR(current);
      }
      
      cout<<"hey"<<endl;
      Fix(root, current);
      cout<<"donde"<<endl;
      cout<<current->getD()<<endl;
    }
  }
  //else if not at end
  else{
    if(data>=current->getD()){
      Node* r = NULL;
      r = current->getR();
      ADD(root, current, r, data);
      return;
      //current->setR(r);
    }
    else if(data<current->getD()){
      Node* l = NULL;
      l = current -> getL();
      ADD(root, current, l, data);
      return;
      //current->setL(l);
    }
  }
  //check for corrections
  /*
  cout<<"hey"<<endl;
  Fix(current);
  cout<<"donde"<<endl;
  cout<<current->getD()<<endl;
  return;*/
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
      Node* tPar = NULL;
      ADD(root, tPar, root, data);//yes. i do want to do this. I think.
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
//am a bit confised how to handle parent. 
void Quit(Node* & current){
  if(!current){
    return;
  }
  Node* L = NULL;
  L = current->getL();
  Quit(L);
  Node* R = NULL;
  R = current->getR();
  Quit(R);
  current->setL(L);
  current->setR(R);
  delete current;
  current=NULL;
}
