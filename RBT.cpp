#include <iostream>
#include "RBT.h"
#include "Node.h"

using namespace std;

RBT::RBT(){
    root = nullptr;
}

void RBT::Insert(int n){
    Insert(head, n);
}

void RBT::Insert(Node* &h, int key){
    if (h == NULL){
        head = new Node(key);
        return;
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
