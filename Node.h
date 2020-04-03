#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <cstring>

//#define CC_RED "\033[34m"

using namespace std;

enum Color {RED, BLACK};
//Colors

class Node{
    public:
      Node(int);
      //Node
      ~Node();
      void setKey(int);
      //Set key
      int getKey();
      //Get key
      void setLeft(Node*);
      //Set left
      Node* getLeft();
      //Get left
      void setRight(Node*);
      //Set right
      Node* getRight();
      //Get right
      void setParent(Node*);
      //Set parent
      Node* getParent();
      //Get parent
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
