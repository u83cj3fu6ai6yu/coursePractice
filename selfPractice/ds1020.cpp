// linklist
// data structure 4-1
// 10/20/2016

#include<iostream>
#include<cstdlib>
#define IS_FULL(temp) (!temp)
using namespace std;

typedef struct list_node *list_pointer;
typedef struct list_node{
	int data;
	list_pointer link;
}list_node;

void insert(list_pointer *ptr, list_pointer node) {
	list_pointer temp;
	temp = (list_node *)malloc( sizeof(list_node) );
	if(IS_FULL(temp)) {
		cout<<stderr<<"The memory is full"<<endl;
		exit(1);
	}
	
	temp->data = 50;
	if(*ptr) {
		temp->link = node->link;
		node->link = temp;
	}
	else {
		temp->link = NULL;
		*ptr = temp;
	}
}

int main() {
	list_pointer ptr = NULL, first, second;
	/*first = (list_pointer) malloc(sizeof(list_node));
	second = (list_pointer) malloc(sizeof(list_node));
	
	ptr = first;
	first->link = second;
	first->data = 10;
	second->link = NULL;
	second->data = 20;
*/	
	cout<<ptr<<endl;
	// create a new node
	insert(&ptr, ptr);
	
	cout<<ptr<<endl;
}
