// dynamically linked queue
// ch4-2 of data structure
// 11/9/2016

#include<iostream>
#include<malloc.h>
#define IS_FULL(temp) (!temp)
using namespace std;

struct element {
	int key;
	char c;
};

typedef struct queue *queue_pointer;
struct queue {
	struct element item;
	queue_pointer link;
};

void addq(queue_pointer *front, queue_pointer *rear, struct element item) {
	// add an element to the rear of the queue
	queue_pointer temp = (queue_pointer) malloc(sizeof(queue));
	if(IS_FULL(temp)) {
		cout<<"The memory is full"<<endl;
		exit(1);
	}
	
	temp->item = item;
	temp->link = NULL;
	if(*front)
		(*rear)->link = temp;
	else
		(*front) = temp;
	(*rear) = temp;
}
struct element delq(queue_pointer *front) {
	if(*front) {
		queue_pointer temp = *front;
		*front = (*front)->link;
		free(temp);
	}
	else {
		cout<<"Queue is empty"<<endl;
		exit(1);
	}
}


int main() {
	queue_pointer front = NULL, rear = NULL;
	struct element item;

	for(int i=0; i<=4; i++) {
		item.c = (char)(97+i);
		item.key = i;
		addq(&front, &rear, item);
	}
	
	delq(&front);
	delq(&front);
	
	for(;front;front = front->link)
		cout<<front->item.c<<'\t'<<front->item.key<<endl;
}
