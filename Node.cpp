//Aparajita Baidya 4.8.2026

#include "Node.h"
#include <iostream>

Node::Node(){
  right = NULL;
  left = NULL;
  parent = NULL;
}

Node::~Node(){
  right = NULL;
  left = NULL;
  parent = NULL;
}

void Node::setR(Node* r){
  right = r;
}

void Node::setL(Node* l){
  left = l;
}

void Node::setP(Node* p){
  parent = p;
}

void Node::setC(string c){
  color = c;
}

void Node::setD(int d){
  data = d;
}

Node* Node::getR(){
  return right;
}

Node* Node::getL(){
  return left;
}

Node* Node::getP(){
  return parent;
}

string Node::getC(){
  return color;
}

int Node::getD(){
  return data;
}
