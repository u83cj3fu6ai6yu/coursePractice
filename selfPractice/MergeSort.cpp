#include<iostream>
#define INF 2147483647
using namespace std;

void Merge(int *A, int l, int m, int r) {
	int n1 = m-l+1, n2 = r-m;
	
	int L[n1+1] = {};
	for(int i=0; i<n1; i++)
		L[i] = A[l+i];
	
	int R[n2+1] = {};
	for(int j=0; j<n2; j++)
		R[j] = A[m+1+j];
	
	L[n1] = INF;
	R[n2] = INF;
	int i=0;
	int j=0;
	
	for(int k=l; k<=r; k++) {
		if(L[i] <= R[j]) {
			A[k] = L[i];
			i++;
		}
		else{
			A[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int *A, int l, int r) {
	if(l != r) {
		int m = (l+r)/2;
		MergeSort(A, l, m);
		MergeSort(A, m+1, r);
		Merge(A, l, m, r);
	}
}

int main() {
	int A[] = {100, 80, 50, 40, 50, 60, 70, 30, 20, 30, 40, 50};
	int len = sizeof(A)/sizeof(A[0]);
	
	MergeSort(A, 0, len-1);
	
	for(int k=0; k<len; k++)
		cout<<A[k]<<'\t';
	return 0;
}
