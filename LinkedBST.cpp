#include <iostream>
#include "LinkedBST.h"

LinkedBST::LinkedBST(){
    root=NULL;
}

LinkedBST::~LinkedBST(){
    
}

void LinkedBST::add(int data){
	if(root==NULL){
		root->info=data;
	}
    else{
        Node* prev= new Node();
        int l=0;
        int r=0;
        prev=root;
        while(prev!=NULL){
            if(data<prev->info){
                prev=prev->left;
                l=1;
            }
            if(data>prev->info){
                prev=prev->right;
                r=1;
            }
        }
        if(l){
            Node* newNode= new Node();
            newNode->info=data;
            newNode->left=newNode->right=NULL;
            prev->left=newNode;
        }
        if(r){
            Node* newNode= new Node();
            newNode->info=data;
            newNode->left=newNode->right=NULL;
            prev->right=newNode;
        }
    }
}


void LinkedBST::preorderTraversal(){
    
}

bool LinkedBST::search(int data){
    Node* prev;
    prev=root;
    while(prev!=NULL){
        if(prev->info==data){
            return true;
        }
        else if(data<prev->info){
            prev=prev->left;
        }
        else if(data>prev->info){
            prev=prev->right;
        }
    }
    return false;
}

int main(){
	LinkedBST a;
	a.add(7);
	a.add(5);
	a.add(4);
	a.add(2);
	a.add(1);
	a.add(6);
	a.add(8);
	
	
    if(a.search(10)){
        std::cout<<"Found"<<std::endl;
    }
    else{
        std::cout<<"Not Found"<<std::endl;
    }
}

