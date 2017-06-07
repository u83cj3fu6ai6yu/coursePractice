// Add the page
// hw9 of algorithm
// 12/20/2016

#include <iostream>
#include <cmath>
using namespace std;

void Solveq(int i, int lack, int miss[], int total[]) {
    int n; // last page
    n = ceil( (-1 + sqrt(1 + 8*lack))/2 );
    if(n == floor( (-1 + sqrt(1 + 8*lack))/2 )) {
        total[i] = ++n;
        miss[i] = n;
    }
    else {
    total[i] = n;
    miss[i] = (1 + n)*n/2 - lack;
    }
}

int main() {
    int n; // # of testing data
    cin>>n;

    int miss[n] = {}, total[n] = {}; // miss (total) array store answer of each missing (total) page
    for(int i=0; i<n; i++) {
        cin>>miss[i];
        Solveq(i, miss[i], miss, total);
    }
    // print answer
    for(int i=0; i<n; i++)
        cout<<miss[i]<<" "<<total[i]<<endl;

    return 0;

}
