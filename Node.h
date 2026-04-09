//Aparajita Baidya 3.8.2026

#ifndef NODE
#define NODE

#include <string>
using namespace std;

class Node{
 private:
  int data;
  string color;
  Node* right;
  Node* left;
  Node* parent;
 public:
  Node();
  ~Node();
  //sets
  void setR(Node* r);
  void setL(Node* l);
  void setP(Node* p);
  void setC(string c);
  void setD(int d);
  //gets
  Node* getR();
  Node* getL();
  Node* getP();
  string getC();
  int getD();
};

#endif //NODE
