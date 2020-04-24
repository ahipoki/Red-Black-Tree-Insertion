#ifndef RBT_H
#define RBT_H

#include "Node.h"

class RBT{
    public:
      RBT();
      //Red-black tree
      void Insert(int);
      //Insert
      void PrintTree();
      //Print tree
      ~RBT();
      //Destructor
    private:
      Node* root;
      //Root node
      void Insert(Node*&, Node*);
      //Private insert function
      void PrintTree(Node*, int);
      //Private printtree function
      void fixTree(Node*);
      //Private fixtree function
      void deleteTree(Node*);
      //Delete the tree
};
#endif
