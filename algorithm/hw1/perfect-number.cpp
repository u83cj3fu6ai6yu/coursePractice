// ������
// �����ƪ��w�q���Y�@�Ӽ�n����ۤv�H�~�����]�ƪ��`�M�h��n��������

#include<iostream>
#include<cmath>
using namespace std;

// �P�_�O�_�������� 
int perfect(int n){
	int sum=1;
	for(int j=2; j<=sqrt(n); j++){
		if(n%j == 0)
			sum += (j + n/j);
	}
	if(sqrt(n) == (int)sqrt(n))
		sum -= sqrt(n);
	if(sum == n)
		return 1;
	else
		return 0;
}



int main(){
	
	int nod;
	cin>>nod;
	int num[nod],yon[nod];//yesorno is for perfect function to store 1 as yes and 0 as no
	for(int i=0; i<nod; i++){
		cin>>num[i];
	}
	
	for(int i=0; i<nod; i++){
		
		yon[i] = perfect(num[i]);
	}
	for(int i=0; i<nod; i++){
		if(yon[i] == 1)
			cout<<num[i]<<" ";
	}
	return 0;
}
