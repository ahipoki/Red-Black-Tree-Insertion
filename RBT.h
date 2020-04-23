#ifndef RBT_H
#define RBT_H

enumc Color {RED, BLACK};

struct Node
{
    int key;
    int color;
    Node *Left, *Right, *Parent;
    
    explicit Node(int);
};

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
      void PrintTree(Node*, int);
      void fixTree(Node*);
      void deleteTree(Node*);
};
#endif
