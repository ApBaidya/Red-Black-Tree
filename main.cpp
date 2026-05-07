/*
Aparajita Baidya 5.6.2026
Red Black Tree

DONE
Insertion due 4.24
-add one number or file input --> update tree
-print
-search

TO DO
Deletion due 5.15
-remove --> update tree
*/

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include "Node.h"

using namespace std;

//function defs
void Case6(Node* & root, Node* & current);
void Case5(Node* & root, Node* & current);
void Case4(Node* & root, Node* & current);
void Case3(Node* & root, Node* & current);
void Case2(Node* & root, Node* & current);
void Case1(Node* & root, Node* & current);
void RemFix(Node* & root, Node* & parent, Node* & current, string Pos, int loops);
void Remove(Node* & root, Node* & current, string originalC);
void FindRemove(Node* & root, Node* & current, int data, string originalC);

void leftRot(Node* & root, Node* & current);
void rightRot(Node* & root, Node* & current);
void Fix(Node* & root, Node* & current);
void ADD(Node* & root, Node* & parent, Node* & current, int data);
void fileADD(Node* & root);
void Display(Node* current, int depth);
void Search(Node* current, int data);
void Quit(Node* & current);

int main(){
  //some variables
  char input[2];//user input
  int running = 1;
  string originalC = "black";
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
      //cout<<root->getD();
      //cout<<"done"<<root->getP()<<endl;
      if(root->getP()!= NULL){
	//cout<<root->getP()->getD()<<root->getP()->getL()->getD()<<root->getL()<<endl;
      }
    }
    if(strcmp(input,"f")==0){
      fileADD(root);
      cout<<"done"<<endl;
    }
    if(strcmp(input,"d")==0){
      //display
      Display(root, 0);
      cout<<"done"<<endl;
    }
    if(strcmp(input,"s")==0){
      cout<<"what value do you wanna look for?"<<endl;
      cin>>data;
      cin.clear();
      Search(root, data);
      cout<<"done"<<endl;
    }
    if(strcmp(input,"r")==0){
      //remove
      cout<<"what do you sentence to death?"<<endl;
      cin>>data;
      cin.clear();
      FindRemove(root, root, data, originalC);
      cout<<"done"<<endl;
    }
    if(strcmp(input,"q")==0){
      //quit
      Quit(root);
      Display(root, 0);
      running = 0;
    }
    cout<<endl;
  }
  cout<<"Bye!"<<endl;
  return 0;
}

void leftRot(Node* & root, Node* & current){
  cout<<"LEFT"<<endl;
  Node* parent = NULL;
  parent=current->getP();
  if(parent==NULL){
    cout<<"rt root"<<endl;
    Node* child = NULL;
    child = current->getR();
    child->setP(NULL);
    current->setR(NULL);
    //safety
    Node* lsub = NULL;
    lsub = child->getL();
    //setting stuff
    current->setR(lsub);
    current->setP(child);
    child->setL(current);
    if(lsub!=NULL){
      lsub->setP(current);
    }
    root = current->getP();
    return;
  }
  //now onto everything that isn't the root
  Node* leftSub = NULL;
  Node* child = NULL;
  child = current->getR();
  leftSub = child->getL();
  child->setL(NULL);
  child->setP(NULL);
  current->setP(NULL);
  current->setR(NULL);
  if(current->getD()>=parent->getD()){//current is right child
    cout<<"L1"<<endl;
    parent->setR(NULL);
    child->setP(parent);
    parent->setR(child);
    child->setL(current);
    current->setP(child);
    current->setR(leftSub);
  }
  else{//left child
    cout<<"L2"<<endl;
    parent->setL(NULL);
    parent->setL(child);
    child->setP(parent);
    child->setL(current);
    current->setP(child);
    current->setR(leftSub);
  }
  if(leftSub!=NULL){
    leftSub->setP(current);
  }
  return;
}

void rightRot(Node* & root, Node* & current){
  Node* parent = NULL;
  cout<<"RIGHT"<<endl;
  //cout<<"find parent"<<endl;
  //cout<<"current data"<<current->getD()<<endl;
  parent = current->getP();
  //cout<<"parent"<<parent<<endl;
  //cout<<"got Parent"<<endl;
  //cout<<"Right time"<<endl;
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
    if(rsub!=NULL){
      rsub->setP(current);
    }
    // cout<<"Ha"<<endl;
    //cout<<current->getP()->getD()<<endl;
    //cout<<"pppp"<<endl;
    //cout<<current->getP()->getL()<<endl;
    root = current->getP();//set root
    return;
  }
  Node* rightSub = NULL;//if child has a right tree
  //Node* grandP = NULL;//not sure why this is needed
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
  return;
}

void Fix(Node* & root, Node* & current){
  cout<<"entered fix"<<endl;;
  Node* parent = NULL;
  //cout<<1<<endl;
  parent = current->getP();
  //cout<<2<<endl;
  if(parent == NULL){
    cout<<"hello, root"<<endl;
    return;
    //return current;
  }
  string unc = "black";
  Node* grandP = NULL;
  grandP = parent->getP();
  //if parent of current is red
  if(parent -> getC() == "red" && current->getC()=="red"){
    //cout<<"a"<<endl;
    //if parent is the left child of it's own parent
    if(parent->getD() < grandP->getD()){
      cout<<"a1"<<"parent is left child of grandP"<<endl;
      //case 1: right child of grandparent is red
      if(grandP->getR()!=NULL){
	//cout<<"a2"<<endl;
	unc = grandP->getR()->getC();
	if(grandP->getR()->getC() == "red"){
	  cout<<"a3"<<"uncle is red"<<endl;
	  //set both children to black and grandP to red
	  parent->setC("black");
	  grandP->getR()->setC("black");
	  grandP->setC("red");
	  cout<<grandP->getC()<<endl;
	  //Fix(root, grandP);
	}
      }//end case 1
      //case 2 uncle is black now t r i a n g l e
      if(unc == "black"){
	if(current->getD()>=parent->getD()){//current is right child of parent
	  //?????????????????????????
	  cout<<"a4"<<"Uncle black - triangle"<<endl;
	  //current -> setC("black");
	  current = parent;
	  //we're gonna take a look at parent
	  leftRot(root, parent);
	  //current->setC("red");
	  //grandP->setC("black");
	  rightRot(root, grandP);
	  current->getP()->setC("black");
	  current->setC("red");
	  grandP->setC("red");
	}
	//case 3 black uncle l i n e
	else{
	  cout<<"a5"<<"Uncle black - line"<<endl;
	  parent->setC("black");
	  grandP->setC("red");
	  rightRot(root, grandP);
	  cout<<grandP->getP()<<endl;
	  //return;// grandP;
	}
      }
    }
    //else
    else{//parent is right child of grandP
      cout<<"b"<<"parent is right child of grandp"<<endl;
      parent = current->getP();
      grandP = current->getP()->getP();
      if(grandP->getL() != NULL){//if grandP's left child is red
	cout<<"b1"<<endl;
	unc = grandP->getL()->getC();
	if(grandP->getL()->getC() == "red"){
	  cout<<"b2"<<"uncle is red"<<endl;
	  grandP->setC("red");
	  grandP->getL()->setC("black");
	  parent->setC("black");
	}
      }
      if(unc == "black"){//else current is left child of parent t r i a n g l e
	if(current->getD() < parent->getD()){
	  //?????????????????????????????
	  cout<<"b3"<<"current is left of parent triangle"<<endl;
	  //current->setC("black");
	  current = parent;
	  rightRot(root, current);
	  //current->setC("black");
	  //grandP->setC("red");
	  leftRot(root, grandP);
	  current->getP()->setC("black");
	  current->setC("red");
	  grandP->setC("red");
	}
	else{//l i n e 
	  cout<<"b4"<<"line"<<endl;
	  parent->setC("black");
	  grandP->setC("red");
	  leftRot(root, grandP);
	}
      }
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
    //cout<<"Parent"<<parent<<endl;
    if(parent!=NULL){
      if(current->getD()<parent->getD()){
	parent->setL(current);
      }
      else{
	parent->setR(current);
      }
      /*      
      cout<<"hey"<<endl;
      Fix(root, current);
      cout<<"donde"<<endl;
      cout<<current->getD()<<endl;*/
    }
  }
  //else if not at end
  else{
    if(data>=current->getD()){
      Node* r = NULL;
      r = current->getR();
      ADD(root, current, r, data);
      //return;
      //current->setR(r);
    }
    else if(data<current->getD()){
      Node* l = NULL;
      l = current -> getL();
      ADD(root, current, l, data);
      //return;
      //current->setL(l);
    }
  }
  //check for corrections
  
  //cout<<"hey"<<endl;
  //cout<<current->getD()<<endl;
  //Display(root, 0);
  Fix(root, current);
  //Display(root, 0);
  //cout<<"donde"<<endl;
  return;
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
    cout<<current->getC()<<" "<<current->getD();
    if(current->getP()!=NULL){
      cout<<"("<<current->getP()->getD()<<")";
    }
    cout<<endl;
    return;
  }
  else{
    //right
    Display(current->getR(), depth+1);
    //center
    for(int i = 0; i < depth; i++){
      cout<<"\t";
    }
    cout<<current->getC()<<" "<<current->getD();
    if(current->getP()!=NULL){
      cout<<"("<<current->getP()->getD()<<")";
    }
    cout<<endl;
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

//OKAY NOW ONTO PART 2 OF THIS CHAOS PROJECT
void Case6(Node* & root, Node* & current){//weirdo case 2
  Node* parent = NULL;
  Node* sibling = NULL;
  Node* impNeph = NULL;
  string rNeph = "red";//default red why not
  string lNeph = "red";
  string pCol;//color of parent
  parent = current->getP();
  if(current->getD()>=parent->getD()){//current is right
    sibling = parent -> getL();
    if(sibling->getL()==NULL){
      lNeph = "black";
    }
    else{
      lNeph = sibling->getL()->getC();
    }
    if(lNeph == "red"){
      impNeph = sibling->getL();
      leftRot(root, parent);//rotate thru parent
      impNeph -> setC("black");
      pCol = parent->getC();//time to switch color of parent and sib
      parent->setC(sibling->getC());
      sibling->setC(pCol);
    }
  }
  else{//current is left
    sibling = parent -> getR();
    if(sibling->getR()==NULL){
      rNeph = "black";
    }
    else{
      rNeph = sibling->getR()->getC();
    }
    if(rNeph == "red"){
      impNeph = sibling->getR();//store that nephew
      rightRot(root, parent);//rotate
      impNeph->setC("black");//swap colors of P and S
      pCol = parent->getC();
      parent->setC(sibling->getC());
      sibling->setC(pCol);
    }
  }
}

void Case5(Node* & root, Node* & current){//weird case and color doesn't matter
  Node* parent = NULL;
  Node* sibling = NULL;
  Node* impNeph = NULL;//the location of the nephew who's color we wanna change
  parent = current->getP();
  string rNeph = "red";//default em to red
  string lNeph = "red";
  //if current is right
  if(current->getD()>=parent->getD()){
    sibling = parent->getL();
    //S ans s's left are black, right is red
    if(sibling->getL() == NULL){//get color of nephews
      lNeph = "black";
    }
    else{
      lNeph = sibling->getL()->getC();
    }
    if(sibling->getR()==NULL){
      rNeph = "black";
    }
    else{
      rNeph = sibling->getR()->getC();
    }
    //now actually do the stuff
    if(sibling->getC()=="black" && lNeph == "black" && rNeph == "right"){
      impNeph=sibling->getR();
      leftRot(root, sibling);
      impNeph->setC("black");
      sibling->setC("red");
    }
    else{
      Case6(root, current);
    }
  }
  //if current is left
  else{
    sibling = parent->getR();
    //get color of nephews
    if(sibling->getL() == NULL){//get color of nephews
      lNeph = "black";
    }
    else{
      lNeph = sibling->getL()->getC();
    }
    if(sibling->getR()==NULL){
      rNeph = "black";
    }
    else{
      rNeph = sibling->getR()->getC();
    }
    //S and s's right are black, left is red
    if(sibling->getC()=="black" && lNeph == "red" && rNeph == "black"){
      impNeph = sibling->getR();
      rightRot(root, sibling);
      impNeph->setC("black");
      sibling->setC("red");
    }
    else{
      Case6(root, current);
    }
  }
}
void RemFix(Node* & root, Node* & parent, Node* & current, string Pos, int loops){
  Node* sibling = NULL;
  Node* distNeph = NULL;
  Node* closeNeph = NULL;
  if(loops>0){
    if(current->getD()<parent->getD()){
      Pos = "L";
    }
    else{
      Pos = "R";
    }
  }
  if(Pos == "L"){
    sibling = parent->getR();
  }
}

void Remove(Node* & root, Node* & current, string originalC){//actual process to delete
  //deletion
  cout<<"found it"<<endl;
  Node* X = NULL;//node that replaces #1
  Node* Y = NULL;//weird in-place successor
  Node* temp = NULL;
  string Pos;//of sibling is right or left
  //C0 we have no kids
  if(current->getR()==NULL && current->getL() == NULL){//delete leaf
    if(root == current){//root case
      cout<<"delete root, all alone"<<endl;
      delete current;
      current = NULL;
      root = NULL;
      return;
    }
    else{
      temp = current->getP();//get parent
      if(current->getD()<temp->getD()){
	temp->setL(NULL);
	Pos = "L";
      }
      else{
	temp->setR(NULL);
	Pos = "R";
      }
      //so, current is now detached from tree
      cout<<"delete leaf"<<endl;
      if(originalC == "black"){//special corrections for single child
	RemFix(root, temp, current, Pos, 0);//sending parent, and Pos of deleted root. Parent to find sibling and such.
      }
      delete current;
      current = NULL;
    }
  }
  //C1 current has one leaf which is the right one, so just replace current
  else if(current->getL()==NULL && current->getR()!= NULL){
    cout<<"delete, has right child"<<endl;
    X = current->getR();
    X->setC("black");
    //X -> setP(current->getP());
    if(current == root){
      delete current;
      X->setP(NULL);
      root = X;
    }
    else{
      X -> setP(current->getP());
      delete current;
      (X->getP())->setR(X);
    }
    return;
  }
  //C2 current has only left leaf so just replace current
  else if(current->getR() == NULL && current->getL()!=NULL){
    cout<<"delete, has left child"<<endl;
    X = current->getL();
    X->setC("black");
    //X -> setP(current->getP());
    if(current == root){
      delete current;
      X->setP(NULL);
      root = X;
    }
    else{
      X -> setP(current->getP());
      delete current;
      (X->getP())->setL(X);
    }
    return;
  }
  //C3 I guess we don't delete the Node at the end first and instead like...Call stuff on it and THEN delete it? Anyways, replace w \
  /successor
  else{//2 kids, crazy
    //will be using x a a temp when finding the successor
    cout<<"delete, has 2 kids"<<endl;
    X = current;
    Y = current->getR();
    while(Y -> getL() != NULL){
      X = Y;
      Y = Y -> getL();
    }
    current->setD(Y->getD());
    //current->setR(Y->getR());
    //current->setL(Y)
    Remove(root, Y, Y->getC());
    return;
  }
}

void FindRemove(Node* & root, Node* & current, int data, string originalC){
  //find the value or dont
  if(current == NULL){//can't find value
    cout<<"nothing to remove"<<endl;
    return;
  }
  originalC = current -> getC();//store original color
  if(current->getD()!=data){//recurse
    cout<<"looking"<<endl;
    if(data < current->getD()){//go left
      Node* l = NULL;
      l = current->getL();
      FindRemove(root, l, data, originalC);
    }
    else{//go right
      Node* r = NULL;
      r = current->getR();
      FindRemove(root, r, data, originalC);
    }
  }
  else{//found node to delete
    Remove(root, current, originalC);
    return;
  }
}
