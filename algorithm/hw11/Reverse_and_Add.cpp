#include <iostream>
#include <cmath>
#include <string.h>
#include <sstream>
using namespace std;

bool isPalindrome(unsigned int num) {
    string str;
    stringstream ss;

    ss<<num;
    ss>>str;
    ss.clear();

    int r = str.length()-1;
    for(int l=0; l<=r; l++) {
        if(str[l] != str[r])
            return false;
        r--;
    }
    return true;
}

void Reverse_Add(unsigned int original, unsigned int* a, unsigned int* b, int i) {
    unsigned int renum, num;
    int c = 0;

    while(true) {
        c++;
        renum = 0;
        num = original;
        while(num) {
            renum = 10*renum + num%10;
            num /= 10;
        }

        original += renum;
        if(isPalindrome(original)) {
            a[i] = c;
            b[i] = original;
            break;
        }
    }
}

int main() {
    int n;
    cin>>n;

    unsigned int num, a[n], b[n];
    for(int i=0; i<n; i++) {
        cin>>num;
        Reverse_Add(num, a, b, i);
    }

    for(int i=0; i<n; i++) {
        cout<<a[i]<<" "<<b[i]<<endl;
    }
}
