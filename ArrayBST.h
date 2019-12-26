#include "BinaryTree.h"

#define MAX_SIZE 16

class ArrayBST: public BinarySearchTree{
	//private:
	
	public:
		ArrayBST();
		~ArrayBST();
		void preorderTraversal();
		void add(int data);
		bool search(int data);
		int element[MAX_SIZE];
};
