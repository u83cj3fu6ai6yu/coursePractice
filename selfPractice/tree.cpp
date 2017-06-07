// tree
// ch5 of data structure
// 11/3/2016

#include<iostream>
#include<malloc.h>
using namespace std;

typedef struct tree *tree_pointer;
struct tree {
	int data;
	tree_pointer llink, rlink;
};

int main() {
	tree_pointer root, B, E, C;
	root = (tree_pointer) malloc(sizeof(tree));
	B = (tree_pointer) malloc(sizeof(tree));
	root->data = 1;
	root->llink = B;
	root->rlink = NULL;
	B->data = 2;
	B->llink = E;
	B->rlink = C;
	
}
