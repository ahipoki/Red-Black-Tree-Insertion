#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int k){
  key = k;
  Right = NULL;
  Left = NULL;
  Parent = NULL;
  isred = false;
}

int Node::getKey(){
  return key;
}

void Node::setKey(int k){
  key = k;
}

Node* Node::getLeft(){
  return Left;
}

void Node::setLeft(Node* n){
  Left = n;
}

Node* Node::getRight(){
  return Right;
}

void Node::setRight(Node* n){
  Right = n;
}

Node* Node::getParent(){
  return Parent;
}

void Node::setParent(Node* n){
  Parent = n;
}

void Node::toggleColor(){
  isred = !isred;
}

bool Node::isRed(){
  return isred;
}

void Node::rotateLeft(){
  if (right == NULL){
    return;
  }
  Node* r = Right;
  Node* p = Parent;
  Right = Right->getLeft();
  r->setLeft(this);
  Parent = r;
  if (Right != NULL){
    Right->setParent(this);
  }
  if (p != NULL){
    if (this == p->getLeft()){
      p->setLeft(r);
    }
    else{
      p->setRight(r);
    }
  }
  r->setParent(p);
  
}
