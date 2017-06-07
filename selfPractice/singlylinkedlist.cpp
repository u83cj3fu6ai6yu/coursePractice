// singly linked list
// ch4-1 of data structure
// 11/9/2016

#include<iostream>
#include<malloc.h>
#define IS_FULL(temp) (!temp)
using namespace std;

typedef struct list *list_pointer;
struct list {
	int data;
	list_pointer link;
};

void insert(list_pointer *ptr, list_pointer node, int data) {
	list_pointer temp;
	temp =(list_pointer) malloc(sizeof(list));
	// heap doesn't have enough memory to give temp
	if(IS_FULL(temp)) {
		cout<<"The memory is full"<<endl;
		exit(1);
	}
	temp->data = data;
	// nonempty list
	if(*ptr) {
		temp->link = node->link;
		node->link = temp;
	}
	else {
		temp->link = NULL;
		*ptr = temp;
	}
}
// delete node after prenode
void del(list_pointer *ptr, list_pointer prenode, list_pointer node) {
	if(prenode)
			prenode->link = node->link;
	else
		*ptr = (*ptr)->link;

	free(node);
}

int main() {
	list_pointer ptr = NULL;
	list_pointer rear = ptr;
	insert(&ptr, rear, 10);
	insert(&ptr, rear, 20);
	insert(&ptr, rear, 30);

	//del(&ptr, ptr->link, ptr->link->link);

	list_pointer iter = ptr;
	for(;iter;iter = iter->link)
		cout<<iter<<'\t'<<iter->data<<'\t'<<iter->link<<endl;
}
