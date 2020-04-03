#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RBT{
    public:
      RBT();
      void Insert(int);
      void Read();
      void PrintTree();
      ~RBT();
    private:
      Node* root;
    protected:
      void rotateLeft(Node*&);
      void rotateRight(Node*&);
      void fixInsert(Node*&);
      int getColor(Node*&);
      void setColor(Node*&, int);
      Node* Insert(Node*&, Node*&);
      void PrintTree(Node*, int);
};
#endif
