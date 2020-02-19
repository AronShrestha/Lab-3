#include <iostream>
#include "LinkedBST.h"

LinkedBST::LinkedBST(){
	root=NULL;
}

LinkedBST::~LinkedBST(){
	
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


void LinkedBST::preorderTraversal(Node *root)
{ 
    if (root == NULL) 
        return; 
  
    std::cout << root->info << " "; 
    preorderTraversal(root->left);  
    preorderTraversal(root->right); 
}

void LinkedBST::preorderTraversal(){
	preorderTraversal(root);
}

void LinkedBST::inorderTraversal(Node* root) 
{ 
    if (root == NULL) 
        return; 
	
	inorderTraversal(root->left);  
    std::cout << root->info << " "; 
  	inorderTraversal(root->right); 
}

void LinkedBST::inorderTraversal(){
	inorderTraversal(root);
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

int LinkedBST::min(Node *root){
	Node *p= root;
	while(p->left!=NULL){
		p=p->left;
		
	}
	return p->info;
}

int LinkedBST::min(){
	min(root);
}

int LinkedBST::max(){
	max(root);
}

int LinkedBST::max(Node* root){
	Node *p=root;
	while(p->right!=NULL){
		p=p->right;
	}
	return p->info;
}

void LinkedBST::delete_node(){
	delete_node(root,6);
}

Node* LinkedBST::delete_node(Node* root, int key){
	if(root==NULL){
		return root;
	}
	if(key<root->info){
		return delete_node(root->left,key);
	}
	else if(key>root->info){
		return delete_node(root->right,key);
	}
	else{
		if(root->left==NULL){
			Node* temp=root->right;
			delete(root);
			return temp;
		}
		else if(root->right==NULL){
			Node *temp=root->left;
			delete(root);
			return temp;
		}
		else{
			Node* current = root->right; 
    		while (current && current->left != NULL) {
    			current = current->left;
			}
			Node* temp=current;
			root->info=temp->info;
			root->right=delete_node(root->right,temp->info);
		}
	}
	return root;
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
	
	std::cout<<"PreOrder Traversal"<<std::endl;
	a.preorderTraversal();
	
	std::cout<<"INOrder Traversal"<<std::endl;
	a.inorderTraversal();
	
	std::cout<<"Delete 5"<<std::endl;
	Node* p=a.delete_node(a.get_root(),5);
	std::cout<<"INOrder Traversal"<<std::endl;
	a.inorderTraversal();
	
    if(a.search(6)){
        std::cout<<"Found"<<std::endl;
    }
    else{
        std::cout<<"Not Found"<<std::endl;
    }
    std::cout<<"the Smallest Key is "<<a.min()<<std::endl;
    std::cout<<"the Largest Key is" <<a.max()<<std::endl;
    
}

