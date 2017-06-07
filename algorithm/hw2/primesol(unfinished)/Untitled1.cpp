#include<iostream>
#include<cmath>
using namespace std;

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

// n for how many prime # add, s for sum, index for which # to start trying
void Recursive(int num, int* four, int n, int s, int index, int* pl){
	for(int j=index; j>=0; j--){
		if(n != 0){
			four[n-1] = j;
			Recursive(num, four, n-1, s-pl[j], index, pl);
		}
		else{
			if(s == 0){
				for(int k=0; k<num; k++)
					cout<<four[k]<<" ";
				cout<<endl;
			}
		}
	}
}

void Findallassemble(int datanum, int* n, int* s, int* pl){
	// i means #-th of measure data
	for(int i=0; i<datanum; i++){
		if(2*n[i] > s[i])
			cout<<"0"<<endl<<endl;
		else{
			int num = n[i], four[num] = {0};
			if(s[i] <= 30)
				Recursive(num, four, n[i], s[i], 9, pl);
		}
	}
}

int main(){
	int pl[62]; // store prime # upto 300
	pl[0] = 2; // first prime # is 2
	Findpl(pl);
	
	int datanum, n[100]={0}, s[100]={0}; // 1<=n<=10000, 2<=s<=300
	cin>>datanum;
	for(int i=0; i<datanum; i++){
		cin>>n[i];
		cin>>s[i];
	}
	
	Findallassemble(datanum, n, s, pl);
	
	return 0;
}
