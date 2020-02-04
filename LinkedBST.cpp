#include <iostream>
#include "LinkedBST.h"

Stack::Stack(){
	stack=NULL;
	top=NULL;
}

Stack::~Stack(){
	
}

LinkedBST::LinkedBST(){
    root=NULL;
}

LinkedBST::~LinkedBST(){
    
}

bool Stack::isEmpty(){
	if(stack==NULL){
		return true;	
	}
	else{
		return false;
	}
}

void Stack::push(Node *a){
	node* newNode= new node();
	newNode->info=a;
	if(isEmpty()){
		newNode->next=newNode;
		stack=newNode;
	}
	else{
		newNode->next=stack->next;
		stack->next=newNode;
	}
}

Node* Stack::pop(){
	if(isEmpty()){
		std::cout<<"Stack Underflow"<<std::endl;
	}
	else{
		top=stack->next;
		Node* data=top->info;
		stack->next=top->next;
		if(top==stack){
			stack=NULL;
		}
		return data;
	}
}





void LinkedBST::add(int data){
	if (isEmpty()) {
	    Node *newNode= new Node();
		root = newNode;
		root->info = data;
	}
	else {
		Node* newnode = root;
		Node* pre = NULL;
		bool l = false;
		bool r = false;
		while (newnode != NULL) {
			pre = newnode;
			l = false;
			if (data < newnode->info) {
				newnode = newnode->left;
				l = true;
			}
			else if (data > newnode->info) {
				newnode = newnode->right;
			}
		}
		if (l) {
			Node* n = new Node();
			n->info = data;
			pre->left = n;
		}
		else {
			Node* n = new Node();
			n->info = data;
			pre->right = n;
		}
	}

}


void LinkedBST::preorderTraversal(){
    Stack st;
	st.push(root);
	Node* a;
	while (!st.isEmpty()) {
		a=st.pop();
		std::cout << a->info << " ";
		if (a->right != NULL)	st.push(a->right);
		if (a->left != NULL)	st.push(a->left);
	}

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

bool LinkedBST::isEmpty() {
	if(root==NULL){
	    return true;
	}
	else{
	    return false;
	}
}

int LinkedBST::min( Node *root){
	Node *p= root;
	while(p->left!=NULL){
		p=p->left;
		
	}
	return p->info;
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
	
	a.preorderTraversal();
	
    if(a.search(6)){
        std::cout<<"Found"<<std::endl;
    }
    else{
        std::cout<<"Not Found"<<std::endl;
    }
    std::cout<<"the Smallest Key is "<<a.min(a.getRoot());
    
}

