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
int ArrayBST::min(){
	ArrayBST::min(1);
}
int ArrayBST::min(int index){
	
	while(index<MAX_SIZE){
		index*=2;	
	}
	return element[index];
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
	
	for(int i=0; i<MAX_SIZE;i++){
		std::cout<<a.element[i];
	}
	std::cout<<std::endl;
	
	a.preorderTraversal();
	
    if(a.search(10)){
        std::cout<<"Found"<<std::endl;
    }
    else{
        std::cout<<"Not Found"<<std::endl;
    }
    std::cout<<"the smallest key is "<<a.min();
}

