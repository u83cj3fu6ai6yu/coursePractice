// age sort

#include<cstdlib>
#include<iostream>
using namespace std;

// switch a and b
void swap3(int &a, int &b){
	int temp = b;
	b = a;
	a = temp;
}

// input b for begin and e for end
void Selectionsort(int* num, int b, int e){
	
	for(int i=b; i<e; i++){
		int min = i;
		for(int j=i+1; j<e; j++){
			if(num[j] < num[min])
				min = j;
		}
		swap3(num[i],num[min]);
	}
}



int main(){
	
	int count=0,num[200000];// store number of data and all number at the same array
	while(1){
		cin>>num[count];
		if(num[count] == 0)
			break;
		count++;
	}
	
	int now = 0;// store which index of array is now at
	while(num[now] != 0){
		Selectionsort(num,now+1,num[now]+now+1);
		for(int k=now+1; k<num[now]+now+1; k++)
			if(k == now+1)
				cout<<num[k];
			else
				cout<<" "<<num[k];
		cout<<endl;
		now += (num[now]+1);
	}
	
	return 0;
}
