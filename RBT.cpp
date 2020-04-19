#include <iostream>
#include "RBT.h"

using namespace std;

RBT::RBT(){//Constructor
    root = nullptr;
    //Root is nullptr
}

void RBT::Insert(int in){
    Node* n = new Node(in);
    Insert(root, n);
    fixTree(n);
}

void RBT::Insert(Node* &h, Node* n){
    if (root == NULL){
        root = n;
        return;
    }
    if (n->key < h->key){
        if (h->Left){
            Node* t = h->Left;
            Insert(t, n);
            return;
        }
        else{
            h->Left = n;
        }
    }
    n->Parent = h;
    if (n->color == BLACK){
        n->color = RED;
    }
}

void RBT::fixTree(Node* n){
    if (n == NULL){
        return;
    }
    if (n->Parent == NULL){
        if (n->color == RED){
            n->color = BLACK;
        }
    }
    else if (n->Parent->color == BLACK){
        
    }
    else if (n->getUncle() && n->getUncle()->color == RED){
        n->Parent->color = RED;
        n->getUncle()->color = RED;
        if (n->Parent->Parent->color == BLACK){
            n->Parent->Parent->color = RED;
        }
        fixTree(n->Parent->Parent);
    }
}

/*int RBT::getColor(Node*& node){//Get color of node
    if (node == nullptr){//If node is null pointer
        return BLACK;
        //Return black
    }
    return node->color;
    //Return color of node
}

void RBT::setColor(Node*& node, int color){//Set color of node
    if (node == nullptr){//If node is null pointer
        return;
        //Return
    }
    node->color = color;
    //Color of node is color
}

void RBT::rotateLeft(Node*& ptr){//Rotate left for fixing
    Node* rightChild = ptr->Right;
    //Right child is right node of ptr
    ptr->Right = rightChild->Left;
    //Right node of ptr is left node of rightChild
    
    if (ptr->Right != nullptr){//If right node of ptr is not null pointer
        ptr->Right->Parent = ptr;
        //Parent of right of ptr node is ptr
    }
    rightChild->Parent = ptr->Parent;
    //Parent node of rightChild is parent node of ptr
    if (ptr->Parent = nullptr){//If parent node of ptr is null pointer
        root = rightChild;
        //Root node is now rightChild
    }
    else if (ptr == ptr->Parent->Left){//Else if ptr equals left of parent of ptr node
        ptr->Parent->Left = rightChild;
        //Left of parent of ptr node is now rightChild
    }
    else{//Anything else
        ptr->Parent->Right = rightChild;
        //Right of parent of ptr node is now rightChild
    }
    rightChild->Left = ptr;
    //Left node of rightChild is now ptr
    ptr->Parent = rightChild;
    //Parent node of ptr is now rightChild
}

void RBT::rotateRight(Node*& ptr){//Rotate right
    Node* leftChild = ptr->Left;
    //leftChild is left node of ptr
    ptr->Left = leftChild->Right;
    //Left node of ptr is now right node of leftChild
    if (ptr->Left != nullptr){//If left node of ptr is not null pointer
        ptr->Left->Parent = ptr;
        //Parent node of left node of ptr is now ptr
    }
    leftChild->Parent = ptr->Parent;
    //Parent node of leftChild is now parent node of ptr
    if (ptr->Parent == nullptr){//If parent node of ptr is null pointer
        root = leftChild;
        //Root node is now leftChild
    }
    else if (ptr == ptr->Parent->Left){//Else if ptr equals left node of parent node of ptr
        ptr->Parent->Left = leftChild;
        //Left node of parent node of ptr is leftChild
    }
    else{//Anything else
        ptr->Parent->Right = leftChild;
        //Right node of parent node of ptr is now leftChild
    }
    leftChild->Right = ptr;
    //Right node of leftChild is now ptr
    ptr->Parent = leftChild;
    //Parent node of ptr is now leftChild
}

void RBT::fixInsert(Node*& ptr){
    Node* Parent = nullptr;
    Node* Grandparent = nullptr;
    while (ptr != root && getColor(ptr) == RED && getColor(ptr->Parent) == RED){
        Parent = ptr->Parent;
        Grandparent = Parent->Parent;
        if (Parent == Grandparent->Left){
            Node* Uncle = Grandparent->Right;
            if (getColor(Uncle) == RED){
                setColor(Uncle, BLACK);
                setColor(Parent, BLACK);
                setColor(Grandparent, RED);
                ptr = Grandparent;
            }
            else{
                if (ptr == Parent->Right){
                    rotateLeft(Parent);
                    ptr = Parent;
                    Parent = ptr->Parent;
                }
                rotateRight(Grandparent);
                swap(Parent->color, Grandparent->color);
                ptr = Parent;
            }
        }
        else{
            Node* Uncle = Grandparent->Left;
            if (getColor(Uncle) == RED){
                setColor(Uncle, BLACK);
                setColor(Parent, BLACK);
                setColor(Grandparent, RED);
                ptr = Grandparent;
            }
            else{
                if (ptr == Parent->Left){
                    rotateRight(Parent);
                    ptr = Parent;
                    Parent = ptr->Parent;
                }
                rotateLeft(Grandparent);
                swap(Parent->color, Grandparent->color);
                ptr = Parent;
            }
        }
    }
    setColor(root, BLACK);
}*/

void RBT::PrintTree(){
    PrintTree(root, 0);
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
