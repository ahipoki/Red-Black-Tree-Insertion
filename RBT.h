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
      void Insert(Node*&, int);
      void Read(Node*&, int);
      void PrintTree(Node*, int);
      Node* head;
};
#endif
