#include<iostream>
using namespace std;

void swap3(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;
}

int main(){
	int c=100,d=40;
	swap3(c,d);
	cout<<d;
}
