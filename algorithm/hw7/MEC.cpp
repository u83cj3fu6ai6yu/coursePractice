// MEC(最小編輯成本)
// hw7 of algorithmics
// 11/29/2016

#include<iostream>
#include<string>
using namespace std;

int minof3num(int a, int b, int c) {
	if(a <= b && a <= c)
		return a;
	else if(b <= a && b <= c)
		return b;
	else
		return c;
}

int MEC(string a, string b) {
	int m = a.length(), n = b.length(), c[m+1][n+1] = {};
	int cost1 = 2, cost2 = 3, cost3 = 4;
	
	for(int i=0; i<=m; i++)
		c[i][0] = i*cost1;
	for(int j=0; j<=n; j++)
		c[0][j] = j*cost2;
	
	for(int i=1; i<=m; i++)
		for(int j=1; j<=n; j++) {
			if(a[i-1] == b[j-1])
				c[i][j] = c[i-1][j-1];
			else{
				c[i][j] = minof3num(c[i-1][j] + cost1, c[i][j-1] + cost2, c[i-1][j-1] + cost3);
			}
		}
	
	return c[m][n];
}

int main() {
	int data;
	cin>>data;
	
	string a, b;
	int ans[data] = {};
	
	getline(cin, a);
	for(int i=0; i<data; i++) {
		getline(cin, a);
		getline(cin, b);
		ans[i] = MEC(a, b);
	}
	for(int i=0; i<data; i++)
		cout<<ans[i]<<endl;
	
	return 0;
}
