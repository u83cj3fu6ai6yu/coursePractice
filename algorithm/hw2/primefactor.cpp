#include<iostream>
#include<cmath>
using namespace std;

int n = 0,count = -1; // global variable for convenient

void Find(int* pnl, int* hmt){
	while(n%pnl[count] == 0){
		hmt[count]++;
		n /= pnl[count];
	}
	
	if(count == 0){
		if(hmt[count] >= 2)
			cout<<pnl[count]<<"^"<<hmt[count];
		else if(hmt[count] == 1)
			cout<<pnl[count];
	}
	else{
		if(hmt[count] >= 2)
			cout<<"*"<<pnl[count]<<"^"<<hmt[count];
		else if(hmt[count] == 1)
			cout<<"*"<<pnl[count];
	}
}

int main(){
	cin>>n;
	cout<<n<<"=";
	
	int num = n; // num store Input # because n will change during calculation
	int pnl[100] = {0}; // pnl is abbreviation of prime # list
	int hmt[100] = {0}; // hmt is abbreviation of how many times in order to store order of every factor
	
	if(num==1)
		cout<<num;
	else
		for(int i=2; i<=num; i++)
			while(n%i == 0){
				count++;
				pnl[count] = i;
				Find(pnl, hmt);
			}
	
	return 0;
}
