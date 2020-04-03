#ifndef RBT_H
#define RBT_H
#include "Node.h"

class RBT{
    public:
      RBT();
      //Red-black tree
      void Insert(int);
      //Insert
      void Read();
      //Read
      void PrintTree();
      //Print tree
      ~RBT();
      //Destructor
    private:
      Node* root;
      //Root node
    protected:
      void rotateLeft(Node*&);
      //Rotate left
      void rotateRight(Node*&);
      //Rotate right
      void fixInsert(Node*&);
      //Fix w/insert
      int getColor(Node*&);
      //Get color of node
      void setColor(Node*&, int);
      //Set color of node
      Node* Insert(Node*&, Node*&);
      //Insert
      void PrintTree(Node*, int);
      //Print tree
};
#endif
