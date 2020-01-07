#include "BinaryTree.h"

class Node{
    public:
			int info;
			Node* left;
			Node* right;
		};

class node{
    public:
        Node* info;
        node* next;
};

class LinkedBST : public BinarySearchTree{
	private:
		Node *root;
	
	public:
	    LinkedBST();
	    ~LinkedBST();
		void preorderTraversal();
		void add(int data);
		bool search(int data);
		bool isEmpty();
		
};

class Stack{
    public:
    Stack();
    ~Stack();
    
    void push(Node* a);
    Node* pop();
    bool isEmpty();
    bool isFull();
    int peak();
    
    private:
    node* stack;
    node* top;
};
