#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

//#define CC_RED "\033[34m"

using namespace std;

enum Color {RED, BLACK};

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
      int color;
    private:
      int Key;
      Node* Left;
      Node* Right;
      Node* Parent;
};
#endif
