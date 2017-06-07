// number sort
// hw3 of algorithmics
// 10/11/2016

#include<iostream>
#include<cstring>
using namespace std;

// comment inside get can sort input string
void get(string &a, int &sum) {
	sum=0;
	for(int i=0; i<a.length(); i++) {
		for(int j=i+1; j<a.length(); j++) {
			if(a[i] > a[j])
				sum++;
		}
	}
}

string sort(string* s, int* degree,int num) {
	string b;
	
	for(int k=0; k<num; k++) {
		get(s[k], degree[k]);
	}
	for(int i=1; i<num; i++) {
		for(int j=i-1; j>=0; j--) {
			if(degree[j] > degree[j+1]) {
				swap(s[j], s[j+1]);
				swap(degree[j], degree[j+1]);
			}
		}
	}
	for(int k=0; k<num; k++)
		b += s[k];
	return b;
/*	for(int i=1; i<num; i++) {
		int j=i-1;
		while(degree[j] > degree[j+1] && j>=0) {
			swap(degree[j], degree[j+1]);
			swap(s[j], s[j+1]);
			j--;
		}
	}
	
	for(int k=0; k<num; k++) {
		cout<<s[k]<<endl;
	}*/
}

string getanswer(int num) {
	string s[num]; // # of string
	int degree[num]={0}; //degree of unsorting
	
	for(int i=0; i<num; i++)
		cin>>s[i];
	
	return sort(s, degree,num);
}

int main() {
	int data; // # of test data
	cin>>data;
	
	int n[data], m[data]; // 0<n<=50, 0<m<=100
	string answer[data];
	
	for(int l=0; l<data; l++) {
		cin>>n[l]>>m[l];
		
		answer[l] = getanswer(m[l]);

		if(l == data-1) {
			for(int i=0; i<data; i++) {
				for(int j=0; j<n[i]*m[i]; j=j+n[i]) {
					for(int k=j; k<j+n[i]; k++)
						cout<<answer[i][k];
					cout<<endl;
				}
				cout<<endl;
			}
		}

	}
	

}
