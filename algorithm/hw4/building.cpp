// building
// hw4 of algorithmics
// 10/22/2016

#include<iostream>
#include<cmath>
#define INF 2147483647
using namespace std;

void Merge(int *floor, int l, int m, int r) {
	int n1 = m-l+1, n2 = r-m;
	
	int L[n1+1] = {};
	for(int i=0; i<n1; i++)
		L[i] = floor[l+i];
	
	int R[n2+1] = {};
	for(int j=0; j<n2; j++)
		R[j] = floor[m+1+j];
	
	L[n1] = INF;
	R[n2] = INF;
	int i=0;
	int j=0;
	
	for(int k=l; k<=r; k++) {
		if(L[i] <= R[j]) {
			floor[k] = L[i];
			i++;
		}
		else{
			floor[k] = R[j];
			j++;
		}
	}
}

void MergeSort(int *floor, int l, int r) {
	if(l != r) {
		int m = (l+r)/2;
		MergeSort(floor, l, m);
		MergeSort(floor, m+1, r);
		Merge(floor, l, m, r);
	}
}

int FindHowManyFloor(int i, int j, int neg, int key, int *floor) {
	int sum = 1;
	while(true) {
		if(i == neg || j == neg-1)
			break;
			
		else{
			if(key == 0) {
				if( floor[j] < abs(floor[i]) ) {
					sum++;
					i++;
					key=1;
				}
				else
					j--;
			}
			else if(key == 1) {
				if( abs(floor[i]) < floor[j] ) {
					sum++;
					j--;
					key=0;
				}
				else
					i++;
			}
		}
	}
	return sum;
}

int Feasible(int num, int pos, int neg, int *floor) {
	MergeSort(floor, 0, num-1);
	
	int sum1 = FindHowManyFloor(0, num-1, neg, 0, floor);
	int sum2 = FindHowManyFloor(0, num-1, neg, 1, floor);
	
	if(sum1 >= sum2)
		return sum1;
	else
		return sum2;
}

int main() {
	int data; // store # of test data
	cin>>data;
	
	int num, floor[500000] = {}, ans[data] = {};
	for(int i=0; i<data; i++) {
		cin>>num;
		
		int pos = 0, neg = 0; // pos store # > 0 & neg store # < 0
		for(int j=0; j<num; j++) {
			cin>>floor[j];
			if(floor[j] > 0)
				pos++;
			else
				neg++;
		}
		ans[i] = Feasible(num, pos, neg, floor);
	}
	
	for(int i=0; i<data; i++)
		cout<<ans[i]<<endl;
		
	return 0;
}
