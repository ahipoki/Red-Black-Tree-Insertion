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
    if (ptr->Key < root->Key){
        root->Left = Insert(root->Left, ptr);
        root->Left->Parent = root;
    }
    else if (ptr->Key > root->Key){
        root->Right = Insert(root->Right, ptr);
        root->Right->Parent = root;
    }
    return root;
}

void RBT::rotateLeft(Node*& ptr){
    Node* rightChild = ptr->Right;
    ptr->Right = rightChild->Left;
    
    if (ptr->Right != nullptr){
        ptr->Right->Parent = ptr;
    }
    rightChild->Parent = ptr->Parent;
    if (ptr->Parent = nullptr){
        root = rightChild;
    }
    else if (ptr == ptr->Parent->Left){
        ptr->Parent->Left = rightChild;
    }
    else{
        ptr->Parent->Right = rightChild;
    }
    rightChild->Left = ptr;
    ptr->Parent = rightChild;
}

void RBT::rotateRight(Node*& ptr){
    
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
