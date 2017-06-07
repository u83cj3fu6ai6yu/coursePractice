// Dynamic programming
// Longest Common Subsequence (LCS)
// 11/1/2016

#include<iostream>
using namespace std;

int LCS(char *X, char *Y) {
	int m = X.length(), n = Y.length();
	int c[X.length()+1][Y.length()+1] = {}, b[X.length()+1][Y.length()+1] = {};
	
	/*for(int i=1; i<=m; i++)
		c[i][0] = 0;
	for(int j=1; j<=n; j++)
		c[0][j] = 0;*/
	
	// left-up = 9, left = 8, up = 7
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++) {
			if(X[i] == Y[j]) {
				c[i][j] = c[i-1][j-1]+1;
				b[i][j] = 9;
			}
			else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
				b[i][j] = 7;
			}
			else {
				c[i][j] = c[i][j-1];
				b[i][j] = 8;
			}
		}
	return c, b;
}

void PRINT_LCS(int b,char *X,int i,int j) { // i 帶入 m, j 帶入 n 
	if(i == 0 || j == 0)
		cout<<"No common subsequence"<<endl;
	else if(b[i][j] == 9) {
		PRINT_LCS(b, X, i-1, j-1);
		cout<<X[i];
	}
	else if(b[i][j] == 7)
		PRINT_LCS(b, X, i-1, j);
	else
		PRINT_LCS(b, X, i, j-1);
}
