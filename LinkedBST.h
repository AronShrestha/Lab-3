#include "BinaryTree.h"

class Node{
			int info;
			Node* left;
			Node* right;
		};

class LinkedBST : public BinarySearchTree{
	private:
		Node *root;
	
	public:
		void preorderTraversal();
		void add(int data);
		bool search(int data);
		
};
