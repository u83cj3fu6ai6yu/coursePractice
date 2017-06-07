// Check whether the credit card number is valid or not
// hw11 of algorithm
// 1/3/2017

#include <iostream>
#include <string.h>
using namespace std;

string isValid(string str) {
    string s = "1234567812345678";
    int j=0;
    for(int i=0; i<str.length(); i++) {
        if(i!=4 && i!= 9 && i!=14) {
            s[j] = str[i];
            j++;
        }
    }

    int sum = 0, ctoi;
    for(int j=0; j<s.length(); j++) {
        if(j%2 == 0) {
            ctoi = (s[j]-48)*2;
            sum += (ctoi%10 + ctoi/10);
        }
        else {
            ctoi = s[j]-48;
            sum += ctoi;
        }
    }

    if(sum%10 == 0)
        return "Valid";
    else
        return "Invalid";
}

int main() {
    int n;
    cin>>n;

    string str, ans[n];
    getline(cin, str);
    for(int i=0; i<n; i++) {
        getline(cin, str);
        ans[i] = isValid(str);
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<endl;

    return 0;
}
