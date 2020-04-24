#include <iostream>
#include "RBT.h"
#include "Node.h"

using namespace std;

RBT::RBT(){//Constructor
    root = NULL;
    //Root is NULL
}

void RBT::Insert(int in){//Public insert function
    Node* n = new Node(in);
    //Node n is a new node with in
    Insert(root, n);
    //Call private insert function with root and n nodes
    fixTree(n);
    //Fixtree with node n
}

void RBT::Insert(Node* &h, Node* n){//Private insert function
    if (root == NULL){//If there is no root node
        root = n;
        //Root node equals node n
        return;
        //Return
    }
    if (n->getKey() < h->getKey()){//If node n's key value is less than node h's key value
        if (h->getLeft()){//If node h's left node
            Node* t = h->getLeft();
            //Node t is now equal to h's left node
            Insert(t, n);
            //Call private insert with nodes t and n
            return;
            //Return
        }
        else{//Anything else
            h->setLeft(n);
            //Set h's left node to n
        }
    }
    else{//Anything else
        if (h->getRight()){//If node h's right node
            Node* t = h->getRight();
            //Node t is now equal to h's right node
            Insert(t, n);
            //Call private insert with nodes t and n
            return;
            //Return
        }
        else{//Anything else
            h->setRight(n);
            //h's right node is now n
        }
    }
    n->setParent(h);
    //Set parent node of n to h
    if (!n->isRed()){//If node n's color is black
        n->toggleColor();
        //Change it to red
    }
}

void RBT::fixTree(Node* n){//Fix tree
    if (n == NULL){//If there is no node N
        return;
        //Return
    }
    if (n->getParent() == NULL){//If there is no parent node of n
        if (n->isRed()){//If node n's color is red
            n->toggleColor();
            //Change it to black
        }
    }
    else if (!n->getParent()->isRed()){//Else if node n's color is black
        //Do nothing
    }
    else if (n->getUncle() && n->getUncle()->isRed()){//Else if it's n's uncle and n's uncle's color is red
        n->getParent()->toggleColor();
        //Change node n's parent node's color to whatever it isn't right now
        //If it's red, change to black
        //If it's black, change to red
        n->getUncle()->toggleColor();
        //Change node n's uncle node to opposite color
        if (!n->getParent()->getParent()->isRed()){//If node n's grandparent node's color is black
            n->getParent()->getParent()->toggleColor();
            //Change node n's grandparent node's color to red
        }
        fixTree(n->getParent()->getParent());
        //Fix tree with node n's grandparent node
    }
    else{//Anything else
        Node* p = n->getParent();
        //Node p is now equal to node n's parent node
        Node* g = p->getParent();
        //Node g is now equal to node p's parent node
        if (n == p->getRight() && p == g->getLeft()){//If node n equals node p's right node and node p equals node g's left node
            p->rotateLeft();
            //Rotate tree left with node p
            n = n->getLeft();
            //Node n now equals node n's left node
        }
        else if (n == p->getLeft() && p == g->getRight()){//Else if node n equals node p's left node and node p equals node g's right node
            p->rotateRight();
            //Rotate tree right with node p
            n = n->getRight();
            //Node n now equals node n's right node
        }
        p = n->getParent();
        //Node p now equals node n's parent node
        g = p->getParent();
        //Node g now equals node p's parent node
        if (n == p->getLeft()){//If node n equals node p's left node
            g->rotateRight();
            //Rotate tree right with node g
        }
        else{//Anything else
            g->rotateLeft();
            //Rotate tree left with node g
        }
        if (g == root){//If node g equals root node
            root = p;
            //Root node now equals node p
        }
        p->toggleColor();
        //Change color of node p
        g->toggleColor();
        //Change color of node g
    }
}

void RBT::PrintTree(){//Public print tree function
    PrintTree(root, 0);
    //Call private print tree function with root and 0
}

void RBT::PrintTree(Node* h, int d){//Private print tree function
    if (!h){//If not node h
        return;
        //Return
    }
    PrintTree(h->getLeft(), d+1);
    //Call private print tree function with node h's left node and d+1
    for (int i = 0; i < d; i++){//For loop
        cout<<"   ";
        //Print spaces between nodes
    }
    cout<<(h->isRed() ? "\033[1;31m" : "\033[1;30m")<<h->getKey()<<"\033[0m"<<endl;
    //Print each node's key value
    //If node's color is red, use red font
    //If node's color is black, use black font
    PrintTree(h->getRight(), d+1);
    //Call private print tree function with node h's right node and d+1
}

RBT::~RBT(){//Destructor

}

void RBT::deleteTree(Node* n){//Delete tree
    if (!n){//If not node n
        return;
        //Return
    }
    deleteTree(n->getLeft());
    //Delete left side
    deleteTree(n->getRight());
    //Delete right side
    delete n;
    //Delete root
}
