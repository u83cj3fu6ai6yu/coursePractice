// �P�_�O�_���ּּ� 
// �Y�N�@�Ӿ��n���Ҧ��Ʀr��}���O�����A�ۥ[�A�p�����жi��ܥu�ѭӦ�Ƥ���A�䵲�G��1�A�h�ڭ̺�n���ּּ�

#include<iostream>
#include<cmath>
using namespace std;

int main(){
	
	int n,str[10],sum,nod;// n store integer input & str store digits for n & sum for addibg all square-digits & nod for number of data
	cin>>nod;
	int num[nod];
	for(int j=0; j<nod; j++){
		cin>>num[j];
	}
	for(int j=0; j<nod; j++){
		
		n = num[j];
		do{
			sum = 0;//zero it
			int count = 0;// for counting how many times while loop
			while(n != 0){
				str[count] = n % 10;
				n /= 10;
				count++;
			}
			
			//int sum = 0;// for addibg all square-digits
			for(int i=0; i<count; i++){
				sum += pow(str[i],2);
			}
			n = sum;
			if(n==1 || n==4 || n==16 || n==37 || n==58 || n==89 || n==145 || n==42 || n==20)
				break;
		}while(1);
		
		if(n == 1)
			num[j] = 1;
		else
			num[j] = 0;
	}
	for(int j=0; j<nod; j++){
		if(num[j] == 1)
			cout<<"Happy"<<endl;
		else
			cout<<"Not Happy"<<endl;
	}
	return 0;	
}
