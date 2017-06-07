// Algorithm 最長共同子序列演算法
// hw6 of algorithmics
// 11/22/2016

#include<iostream>
#include<string>
using namespace std;

int LCS(string X, string Y) {
	int m = X.length(), n = Y.length();
	int c[m+1][n+1] = {};

	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++) {
			if(X[i-1] == Y[j-1]) {
				c[i][j] = c[i-1][j-1]+1;
			}
			else if(c[i-1][j] >= c[i][j-1]) {
				c[i][j] = c[i-1][j];
			}
			else {
				c[i][j] = c[i][j-1];
			}
		}
	}
	return c[m][n];
}

int main() {
	int n;
	string s1, s2;
	// get # of pair of sequence
	cin>>n;
	int ans[n] = {};
	getline(cin, s1);
	// get pair of sequence and store length of LCS into ans array
	for(int i=0; i<n; i++) {
		getline(cin, s1);
		getline(cin, s2);
		ans[i] = LCS(s1, s2);
	}
	// print the answer
	for(int i=0; i<n; i++) {
		cout<<ans[i]<<endl;
	}
	return 0;
}
