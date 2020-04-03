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
};
#endif
