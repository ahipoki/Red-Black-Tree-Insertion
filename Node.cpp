#include <iostream>
#include <cstring>
#include "Node.h"

using namespace std;

Node::Node(int key){
    Key = key;
    Left = NULL;
    Right = NULL;
    Parent = NULL;
}

void Node::setKey(int key){
    Key = key;
}

int Node::getKey(){
    return Key;
}

void Node::setLeft(Node* left){
    Left = left;
}

Node* Node::getLeft(){
    return Left;
}

void Node::setRight(Node* right){
    Right = right;
}

Node* Node::getRight(){
    return Right;
}

void Node::setParent(Node* parent){
    Parent = parent;
}

Node* Node::getParent(){
    return Parent;
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

Node::~Node(){
    
}
