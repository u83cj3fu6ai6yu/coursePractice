// Dynamically Linked Stacks
// data structure 4-2
// 10/20/2016

#include<iostream>
#include<malloc.h>
#define IS_FULL(temp) (!temp)
#define IS_EMPTY(temp) (!temp)
#define MAX_STACKS 10
using namespace std;

struct element {
	int key;
	char c;
};

typedef struct stack *stack_pointer;
struct stack {
	struct element item;
	stack_pointer link;
};
//stack_pointer top[MAX_STACKS];

// Push in the linked stack
void add(stack_pointer *top, struct element item) {
	// add an element to the top of the stack
	stack_pointer temp = (stack_pointer) malloc(sizeof(stack));
	
	if(IS_FULL(temp)) {
		cout<<"The memory is full"<<endl;
		exit(1);
	}
	
	temp->item = item;
	temp->link = *top;
	*top = temp;
}

// Pop from the linked stack
struct element del(stack_pointer *top) {
	stack_pointer temp = *top;
	struct element item;
	
	if(IS_EMPTY(temp)) {
		cout<<"The stack is empty"<<endl;
		exit(1);
	}
	
	item = temp->item;
	*top = temp->link;
	free(temp);
	
	return item;
}

int main() {
	stack_pointer top = NULL;
	
	struct element item;
	for(int i=0; i<=4; i++) {
		item.c = (char)(i+97);
		item.key = i;
		add(&top, item);
	}
	
	//item = del(&top);
	item = del(&top);
	cout<<item.c<<'\t'<<item.key<<"~~~~~~"<<endl;
	
	for(;top;top = top->link)
		cout<<top->item.c<<'\t'<<top->item.key<<endl;
}
