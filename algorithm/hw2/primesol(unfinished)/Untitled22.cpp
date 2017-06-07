#include<iostream>
#include<cmath>
using namespace std;

// global variable
int pl[62] = {2}; // store prime # upto 300, first one is 2
int datanum, n[100] = {0}, s[100] = {0}; // 1<=n<=10000, 2<=s<=300
int num;

// Find out all prime # from 2 ~ 300
void Findpl(int* pl){
	int k,count = 0;
	for(int i=3; i<300; i++){
		k = 0; // if k becomes 1, i is not a prime #
		
		for(int j=2; j<=sqrt(i); j++)
			if(i%j == 0){
				k = 1;
				break;
			}
		
		if(k == 0){
			count++;
			pl[count] = i;
		}
	}
}

void Recursive(int n, int s, int index, int* noa){
	if(n != 0){
		for(int j=index; j>=0; j--){
			noa[n-1] = pl[j];
			if(noa[n-2] > noa[n-1]){
				break;
			}
			Recursive(n-1, s-pl[j], index, noa);
		}
	}
	else{
		if(s == 0){
			int key = 0;
			for(int k=0; k<num-1; k++){
				if(noa[k] > noa[k+1])
					key = 1;
			}
			if(key == 0){
				for(int k=0; k<num; k++)
					cout<<noa[k]<<" ";
				cout<<endl;
			}
		}
	}
}

void Findallassemble(){
	// i means #-th of measure data
	for(int i=0; i<datanum; i++){
		if(2*n[i] > s[i])
			cout<<"0"<<endl<<endl;
		else{
			num = n[i];
			int index, noa[num] = {0}; // number of addition
			for(int m=0; m<62; m++){
				if(pl[m] <= s[i])
					index = m;
				else
					break;
			}
			Recursive(n[i], s[i], index, noa);
			cout<<endl;
		}
	}
}

int main(){

	Findpl(pl);
	
	cin>>datanum;
	for(int i=0; i<datanum; i++){
		cin>>n[i];
		cin>>s[i];
	}
	
	Findallassemble();	
}
