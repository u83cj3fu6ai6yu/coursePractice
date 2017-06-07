// ¯x°}Ãì­¼¿nºtºâªkMATRIX_CHAIN_ORDER
// hw6 of algorithmic
// 11/22/2016

#include<iostream>
#define INF 10000000
using namespace std;

int M_C_O(int *p, int n) {
	int j, q, m[n+1][n+1] = {};
	
	for(int l=2; l<=n; l++) {
		for(int i=1; i<=n-l+1; i++) {
			j = i+l-1;
			m[i][j] = INF;
			for(int k=i; k<=j-1; k++) {
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
				if(q < m[i][j])
					m[i][j] = q;
			}
		}
	}
	
	return m[1][n];
}

int main() {
	int k;
	cin>>k;
	int matrix[k+1] = {};
	for(int i=0; i<=k; i++)
		cin>>matrix[i];
	
	cout<<M_C_O(matrix, k)<<endl;
	return 0;
}
