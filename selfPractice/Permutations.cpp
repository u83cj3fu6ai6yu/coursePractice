// Permutations

#include<iostream>
using namespace std;

void permutations(char *A, int i, int n) {
	int j;
	if(i == n) {
		for(int j=0; j<=n; j++)
			cout<<A[j];
		cout<<'\t';
	}
	else {
		for(j=i; j<=n; j++) {
			swap(A[i], A[j]);
			permutations(A, i+1, n);
			swap(A[i], A[j]);
		}
	}
}

int main() {
	char A[] = {'a', 'b', 'c'};
	int len = sizeof(A)/sizeof(A[0]);
	
	permutations(A, 0, len-1);
	
	return 0;
}
