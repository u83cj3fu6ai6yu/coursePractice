// Maximum Contiguous Subsequence Sum
// hw4 of algorithmics
// 10/18/2016

#include<iostream>
#define INF 2147483647
using namespace std;

int MAX(int a, int b, int c) {
	if(a>=b && a>= c)
		return a;
	else if(b>=a && b>=c)
		return b;
	else
		return c;
}

int MCSS(int *s, int l, int r) {
	if(l == r)
		return s[l];
	
	int md = (l+r)/2;
	int ml = MCSS(s, l, md);
	int mr = MCSS(s, md+1, r);
	
	int mbl = -INF, t=0;
	for(int i=md; i>=l; i--) {
		t += s[i];
		if(t > mbl)
			mbl = t;
	}
	
	int mbr = -INF;
	t=0;
	for(int i=md+1; i<=r; i++) {
		t += s[i];
		if(t > mbr)
			mbr = t;
	}
	
	int mb;
	if(mbl>0 && mbr>0)
		mb = mbl + mbr;
	else
		mb = MAX(mbr, mbl, -INF);
	
	return MAX(ml, mr, mb);
}

int main() {
	int N; // # of sequence
	cin>>N;
	
	int s[10]; // store input sequence
	int answer[N]; // store answer of each sequence
	for(int i=0; i<N; i++) {
		for(int j=0; j<10; j++)
			cin>>s[j];
		answer[i] = MCSS(s, 0, 9);
	}
	
	for(int i=0; i<N; i++)
		cout<<answer[i]<<endl;
	return 0;
}
