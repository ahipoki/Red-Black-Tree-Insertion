#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

using namespace std;

class Node{
    public:
      Node(int);
      ~Node();
      void setKey(int);
      int getKey();
      void setLeft(Node*);
      Node* getLeft();
      void setRight(Node*);
      Node* getRight();
      void setParent(Node*);
      Node* getParent();
      //Node* getUncle(Node*);
      //Node* getSibling(Node* );
    private:
      int Key;
      bool Color;
      Node* Left;
      Node* Right;
      Node* Parent;
};
#endif
