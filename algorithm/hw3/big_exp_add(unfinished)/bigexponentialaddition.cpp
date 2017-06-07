// Big Exponential Addition
// hw3 of algorithmics
// 10/11/2016

#include<iostream>
#include<cmath>
using namespace std;

//unsigned long long int biggest = 18446744073709551615;
//sqrt(biggest) = 4000000000
// array[] can save not over 4000000000

void printanswer(int m, int n) {
	// first find out the difference between m & n;
	int dif = abs(m-n), other;
	if(m >= n) {
		other = m-dif;
	}
	else
		other = n-dif;
	// second find out dif & other
	int leveldif[5] = {0}, levelother[5] = {0};
	unsigned long long int array[6] = {2, 4, 16, 256, 65536, 4294967296};
	int j=5, order=32;
	while(dif%order != 0 && j >= 0) {
		leveldif[j] = dif / order;
		dif = dif % order;
		order /= 2;
		j--;
	}
	leveldif[j] = dif/order;
	j=5; order=32;
	while(other%order != 0 && j >= 0) {
		levelother[j] = other / order;
		other = other % order;
		order /= 2;
		j--;
	}
	levelother[j] = other/order;
	for(int i=0; i<6; i++)
		cout<<levelother[i]<<endl;
}

int main() {
	int data;
	cin>>data;
	
	int m[data], n[data];
	for(int i=0; i<data; i++)
		cin>>m[i]>>n[i];
	
	for(int i=0; i<data; i++) {
		printanswer(m[i], n[i]);
	}
}
