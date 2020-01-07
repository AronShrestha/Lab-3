#include "BinaryTree.h"

#define MAX_SIZE 16

class ArrayBST: public BinarySearchTree{
	
	public:
		ArrayBST();
		~ArrayBST();
		void preorderTraversal(int index);
		void add(int data);
		bool search(int data);
		int element[MAX_SIZE];
		int get_left_child(int index);
		int get_right_child(int index);
};
