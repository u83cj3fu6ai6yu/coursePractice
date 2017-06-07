// find the odd sum without prime number
// hw11 of algorithm
// 1/3/2017

#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int i) {
    for(int j=2; j<=sqrt(i); j++) {
        if(i%j == 0)
            return false;
    }
    return true;
}

int Odd_Sum(int a, int b) {
    int sum = 0;
    for(int i=a; i<=b; i++)
        if(i%2 == 1)
            if(!isPrime(i))
                sum += i;

    return sum;
}

int main() {
    int n;
    cin>>n;

    int a, b, ans[n];
    for(int i=0; i<n; i++) {
        cin>>a>>b;
        ans[i] = Odd_Sum(a, b);
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<endl;

    return 0;
}
