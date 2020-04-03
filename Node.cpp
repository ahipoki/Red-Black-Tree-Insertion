#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int key){
    this->Key = key;
    //this key is key
    color = RED;
    //Color is red
    Left = Right = Parent = nullptr;
    //Left, right, and parent are nullptr
}

void Node::setKey(int key){//Set key
    Key = key;
    //Key is key
}

int Node::getKey(){//Get key
    return Key;
    //Return key
}

void Node::setLeft(Node* left){//Set left node
    Left = left;
    //Left is left
}

Node* Node::getLeft(){//Get left node
    return Left;
    //Return left node
}

void Node::setRight(Node* right){//Set right node
    Right = right;
    //Right is right
}

Node* Node::getRight(){//Get right node
    return Right;
    //Return right node
}

void Node::setParent(Node* parent){//Set parent node
    Parent = parent;
    //Parent is parent
}

Node* Node::getParent(){//Get parent node
    return Parent;
    //Return parent node
}

/*Node* Node::getSibling(Node* p){
    Node* p = getParent();
    if (p == nullptr){
        return nullptr;
    }
    if (n == p->getLeft()){
        return p->getRight();
    }
    else{
        return p->getLeft();
    }
}

Node* Node::getUncle(Node* n){
    Node* p = getParent();
    return getSibling(p);
}*/

Node::~Node(){//Destructor
    
}
