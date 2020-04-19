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
      void Read();
      //Read
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
    protected:
      void rotateLeft(Node*&);
      //Rotate left
      void rotateRight(Node*&);
      //Rotate right
      //void fixInsert(Node*&);
      //Fix w/insert
      //int getColor(Node*&);
      //Get color of node
      //void setColor(Node*&, int);
      //Set color of node
};
#endif
