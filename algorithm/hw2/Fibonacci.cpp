// Fibonacci
// Input 第一行是測資個數k接下來一行一個數字n,共k行

#include<iostream>
using namespace std;

void Fibonacci(int* Fib, int max){
	Fib[0] = 0;
	Fib[1] = 1;
	if(max >= 2)
		for(int i=2; i<=max; i++)
			Fib[i] = Fib[i-1] + Fib[i-2];
}

int main(){
	int k; //# of data
	cin>>k;
	
	int n[k], max=0; // n[k] store data & max store the biggest # of data
	for(int i=0; i<k; i++){
		cin>>n[i];
		if(n[i] > max)
			max = n[i];
	}
	
	int Fib[max+1]; // Here need max+1 column because array's index starts from 0 
	Fibonacci(Fib,max);
	
	for(int i=0; i<k; i++)
		cout<<Fib[ n[i] ]<<endl;
		
	return 0;
}
