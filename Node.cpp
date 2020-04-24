#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(int k){
  key = k;
  //Key
  Right = NULL;
  Left = NULL;
  Parent = NULL;
  //Right, Left, and Parent are set to NULL
  isred = false;
  //isred is set to false
}

int Node::getKey(){//Get key
  return key;
  //Return key
}

void Node::setKey(int k){//Set key
  key = k;
  //Key equals k
}

Node* Node::getLeft(){//Get left
  return Left;
  //Return left node
}

void Node::setLeft(Node* n){//Set left
  Left = n;
  //Left node equals n
}

Node* Node::getRight(){//Get right
  return Right;
  //Return right node
}

void Node::setRight(Node* n){//Set right
  Right = n;
  //Right node equals n
}

Node* Node::getParent(){//Get parent
  return Parent;
  //Return parent node
}

void Node::setParent(Node* n){//Set parent
  Parent = n;
  //Parent node equals n
}

void Node::toggleColor(){//Toggle color
  isred = !isred;
  //Change color of node
  //If red, becomes black
  //If black, becomes red
}

bool Node::isRed(){//Check node's color
  return isred;
  //Return node's color
}

void Node::rotateLeft(){//Rotate left
  if (right == NULL){//If there's no node to the right
    return;
    //Return
  }
  Node* r = Right;
  //Node r equals right node
  Node* p = Parent;
  //Node p equals parent node
  Right = Right->getLeft();
  //Right node is now the value of the right node's left node
  r->setLeft(this);
  //Set r node to this
  Parent = r;
  //Parent node value is now r's value
  if (Right != NULL){//If there is a right node
    Right->setParent(this);
    //Set the parent of the right node to this
  }
  if (p != NULL){//If there is a p node
    if (this == p->getLeft()){//If this equals left node of p
      p->setLeft(r);
      //Set left node of p to r
    }
    else{//Anything else
      p->setRight(r);
      //Set right node of p to r
    }
  }
  r->setParent(p);
  //Set parent of r node to p
}

void Node::rotateRight(){//Rotate right
  if (Left == NULL){//If there's no left node
    return;
    //Return
  }
  Node* l = Left;
  //Node l equals left
  Node* p = Parent;
  //Node p equals parent
  Left = Left->getRight();
  //Left now equals left node's right node
  l->setRight(this);
  //Set right node of l to this
  Parent = l;
  //Set parent node to l
  if (Left != NULL){//If there is a left node
    Left->setParent(this);
    //Set parent of left node to this
  }
  if (p != NULL){//If there is a p node
    if (this == p->getLeft()){//If this equals left node of p
      p->setLeft(l);
      //Set left node of p to l
    }
    else{//Anything else
      p->setRight(l);
      //Set right node of p to l
    }
  }
  l->setParent(p);
  //Set parent node of l to p
}

Node* Node::getSibling(){//Get sibling
  if (Parent == NULL){//If there's no parent node
    return NULL;
    //Return NULL
  }
  if (this == Parent->getLeft()){//If this equals left node of parent
    return Parent->getRight();
    //Return right node of parent
  }
  return Parent->getLeft();
  //Otherwise return left node of parent
}

Node* Node::getUncle(){//Get uncle
  if (Parent == NULL){//If there's no parent node
    return NULL;
    //Return NULL
  }
  return Parent->getSibling();
  //Otherwise return the parent node's sibling (uncle)
}

Node::~Node(){//Destructor
  
}
