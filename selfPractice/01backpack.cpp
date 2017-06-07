// Dynamic programming
// 01­I¥]°ÝÃD 
// 11/1/2016

#include<iostream>
using namespace std;

int KnapSack(int *v, int *w, int n, int W) {
	int V[n+1][W+1] = {};
	
	for(int i=1; i<=n; i++)
		for(int j=0; j<=W; j++) {
			if(w[i] <= w && v[i] + V[i-1][w-w[i]] > V[i-1][w]) {
				V[i][w] = v[i] + V[i-1][w-w[i]];
				keep[i][w] = 1;
			}
			else {
				V[i][w] = V[i-1][w];
				keep[i][w] = 0;
			}
		}
	K = W;
	for(i=n; i>=1; i--)
		if(keep[i][K] == 1) {
			cout<<i<<endl;
			K -= w[i];
		}
	return V[n][W];
}
