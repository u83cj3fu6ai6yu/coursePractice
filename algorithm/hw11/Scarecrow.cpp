// at least need how many scarecrows to cover field
// hw11 of algorithm
// 1/3/2017

#include <iostream>
#include <string.h>
using namespace std;

int scarecrowNum(string str) {
    int ans = 0;
    for(int j=0; j<str.length(); j++) {
        if(str[j] == '.') {
            j += 2;
            ans++;
        }
    }

    return ans;
}

int main() {
    int T;
    cin>>T;


    int N, ans[T];
    string str;
    getline(cin, str);
    for(int i=0; i<T; i++) {
        cin>>N;
        getline(cin, str);
        getline(cin, str);
        ans[i] = scarecrowNum(str);
    }

    for(int i=0; i<T; i++)
        cout<<"Case "<<i+1<<": "<<ans[i]<<endl;

    return 0;
}
