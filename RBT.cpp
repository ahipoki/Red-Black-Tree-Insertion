#include <iostream>
#include "RBT.h"
#include "Node.h"

using namespace std;

RBT::RBT(){
    root = nullptr;
}

int RBT::getColor(Node*& node){
    if (node == nullptr){
        return BLACK;
    }
    return node->color;
}

void RBT::setColor(Node*& node, int color){
    if (node == nullptr){
        return;
    }
    node->color = color;
}

void RBT::Insert(int n){
    Node* node = new Node(n);
    root = Insert(root, node);
    fixInsert(node);
}

void RBT::Insert(Node*& root, Node*& ptr){
    if (root == nullptr){
        return ptr;
    }
    else if (key < h->getKey()){
        if (h->getLeft() == NULL){
            h->setLeft(new Node(key));
            h->getLeft()->setParent(h);
            return;
        }
        Node* left = h->getLeft();
        Insert(left, key);
        return;
    }
    else{
        if (h->getRight() == NULL){
            h->setRight(new Node(key));
            h->getRight()->setParent(h);
            return;
        }
        Node* right = h->getRight();
        Insert(right, key);
        return;
    }
}

void RBT::PrintTree(){
    PrintTree(head, 0);
}

void RBT::PrintTree(Node* h, int d){
    if (!h){
        return;
    }
    if (h->getLeft()){
        PrintTree(h->getLeft(), d+1);
    }
    for (int i = 0; i < d; i++){
        cout<<"   ";
    }
    cout<<h->getKey()<<endl;
    if (h->getRight()){
        PrintTree(h->getRight(), d+1);
    }
}

RBT::~RBT(){

}
