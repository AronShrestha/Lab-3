#include <iostream>
#include "ArrayBST.h"

ArrayBST::ArrayBST(){
	for(int i=0;i<MAX_SIZE;i++){
		this->element[i]=0;
	}
}

ArrayBST::~ArrayBST(){
	
}


void ArrayBST::add(int data){
	if(this->element[0]==0){
		element[1]=data;
	}
	else{
		for(int i=1;i<=MAX_SIZE; ){
			if(data<this->element[i]){
				i=2*i;
			}
			else{
				i=2*i+1;
			}
			if(this->element[i]==0){
				this->element[i]=data;
				break;
			}
		}
	}
	this->element[0]=this->element[0]+1;
}

int ArrayBST::get_left_child(int index){
    if(element[index]!=0 && (2*index)<=MAX_SIZE){
        return 2*index;
    }
    return -1;
}

int ArrayBST::get_right_child(int index){
    if(element[index]!=0 && (2*index+1)<=MAX_SIZE){
        return 2*index+1;
    }
    return -1;
}

void ArrayBST::preorderTraversal(){
	preorderTraversal(1);
}

void ArrayBST::preorderTraversal(int index){
	if(index>0 && element[index]!=0)
    {
        std::cout<<element[index]<<std::endl;
        preorderTraversal(get_left_child(index));
        preorderTraversal(get_right_child(index));
    }
}

void ArrayBST::inorderTraversal(){
	inorderTraversal(1);
}

void ArrayBST::inorderTraversal(int index){
	if(index>0 && element[index]!=0){
		inorderTraversal(get_left_child(index));
		std::cout<<element[index]<<std::endl;
		inorderTraversal(get_right_child(index));
	}
}

bool ArrayBST::search(int data){
	int current_index=1;
	while(current_index<=MAX_SIZE){
	    if(element[current_index]==data){
	        return true;
	        break;
	    }
	    else if(element[current_index]>data){
	        current_index=2*current_index;
	    }
	    else if(element[current_index]<data){
	        current_index=2*current_index+1;
	    }
	}
	return false;
}

int ArrayBST::max(int index){
	while(index<=MAX_SIZE){
		if(element[index]!=0 && (2*index+1)<=MAX_SIZE){
        index=2*index+1;
    }
		if(element[2*index+1]==0){
			return element[index];
		}
	}
}
int ArrayBST::max(){
	max(1);
} 

int ArrayBST::min(int index){
	while(index<=MAX_SIZE){
		if(element[index]!=0 && (2*index)<=MAX_SIZE){
			index=2*index;
		}
		if(element[2*index]==0){
			return element[index];
		}
	}
}

int ArrayBST::min(){
	min(1);
}

void ArrayBST::delete_node(int index,int key){
	while((element[index]!=key) && (element[index] != 0)){
        if(key < element[index]){
        	index = 2 * index;
		}
        else{
        	index = 2 * index + 1;
		}
	}
	if(element[index]!=0){
		if(element[2*index]==0 && element[2*index+1]==0){
			std::cout<<"First"<<std::endl;
			element[index]==0;
		}
		else if(element[2*index]==0 || element[2*index+1]==0){
			std::cout<<"Second"<<std::endl;
			if(element[2*index+1]==0){
				element[index]==element[2*index];
			}
			else{
				element[index]==element[2*index+1];
			}
		}
		else{
			std::cout<<"Third"<<std::endl;
			int temp=element[index];
			int m=max(2*index);
			std::cout<<"MAX"<<m;
			element[index]=m;
			delete_node(2*index,m);
		}
	}
}

void ArrayBST::delete_node(){
	delete_node(1,6);
}
int main(){
	ArrayBST a;
	a.add(7);
	a.add(5);
	a.add(4);
	a.add(2);
	a.add(1);
	a.add(6);
	a.add(8);
	a.add(12);
		
		
	for(int i=0;i<MAX_SIZE;i++){
		std::cout<<a.element[i]<<std::endl;
	}
	std::cout<<"PreorderTraversal"<<std::endl;
	a.preorderTraversal();
	
	std::cout<<"InorderTraversal"<<std::endl;
	a.inorderTraversal();
	
    if(a.search(10)){
        std::cout<<"Found"<<std::endl;
    }
    else{
        std::cout<<"Not Found"<<std::endl;
    }
    std::cout<<"Maximum element is"<<a.max()<<std::endl;
    std::cout<<"Minimum element is"<<a.min()<<std::endl;
    
    a.delete_node();
    std:: cout<<"After delete"<<std::endl;
    for(int i=0;i<MAX_SIZE;i++){
		std::cout<<a.element[i]<<std::endl;
	}
    a.inorderTraversal();
    
}

