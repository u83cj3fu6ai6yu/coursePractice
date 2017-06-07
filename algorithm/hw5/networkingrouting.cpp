// 網路路由問題
// hw5 of algorithmics
// 10/25/2016

#include<iostream>
#include<iomanip>
#define INF 147483647
using namespace std;

int main() {
	int N, M, K;
	cin>>N>>M>>K;
	
	int pdelay[N] = {};
	int edelay[N][N] = {};
	// input point delay meanwhile set delay of point to itself as infinity
	for(int i=0; i<N; i++) {
		cin>>pdelay[i];
		edelay[i][i] = 0;
	}
	// input edge delay
	int a, b, c;
	for(int i=0; i<M; i++) {
		cin>>a>>b>>c;
		edelay[a-1][b-1] = c;
		edelay[b-1][a-1] = c;
	}
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			if(edelay[i][j] == 0 && i!=j)
				edelay[i][j] = INF;
		}
	}
	// input required two point
	int required[2*K] = {};
	for(int i=0; i<2*K; i+=2)
		cin>>required[i]>>required[i+1];
	/*cout<<"Before"<<endl;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++)
			cout<<setw(15)<<edelay[i][j];
		cout<<endl;
	}*/
	// Find the shortest distance between every two points
	for(int k=0; k<N; k++)
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++) {
					if(edelay[i][k] == INF || edelay[k][j] == INF)
						continue;
					else
						edelay[i][j] = min(edelay[i][j], edelay[i][k] + edelay[k][j] + pdelay[k]);
			}
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			if(i != j)
				edelay[i][j] += (pdelay[i] + pdelay[j]);
	/*cout<<"After"<<endl;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++)
			cout<<setw(15)<<edelay[i][j];
		cout<<endl;
	}*/
	// print the answer
	for(int i=0; i<2*K; i+=2) {
		if(required[i] == required[i+1])
			cout<<0;
		else
			cout<<edelay[required[i]-1][required[i+1]-1]<<endl;
	}
	
	return 0;
}
