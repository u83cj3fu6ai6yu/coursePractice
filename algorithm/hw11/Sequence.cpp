#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

string isTrue(vector<int> &seq) {
    int sum;
    for(int i=0; i<seq.size(); i++)
        for(int j=i+1; j<seq.size(); j++) {
            sum = seq.at(i) + seq.at(j);
            for(int k=0; k<seq.size(); k++)
                if(seq.at(k) == sum)
                    return "false";
        }

    return "true";
}

int main() {
    int n;
    cin>>n;

    int m, num;
    vector<int> seq;
    string ans[n];
    for(int i=0; i<n; i++) {
        cin>>m;
        for(int j=0; j<m; j++) {
            cin>>num;
            seq.push_back(num);
        }
        ans[i] = isTrue(seq);
        seq.clear();
    }

    for(int i=0; i<n; i++)
        cout<<ans[i]<<endl;

    return 0;
}
