// subset sum
// hw10 of algorithm
// 12/27/2016

#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

bool subsetSum(vector<int> &v, int target) {
    int value[v.size()+1][target+1] = {};

    for(int i=1; i<=v.size(); i++)
        for(int w=0; w<=target; w++) {
            if(v.at(i-1) <= w)
                value[i][w] = max(value[i-1][w], v.at(i-1) + value[i-1][w-v.at(i-1)]);
            else
                value[i][w] = value[i-1][w];
        }

    if(value[v.size()][target] == target)
        return true;
    else
        return false;
}

int main() {
    int sum, target, n;
    string str;
    vector<int> v;

    cin>>n;
    getline(cin, str);
    bool ans[n];
    for(int k=0; k<n; k++) {
        getline(cin, str);
        v.clear();
        sum = 0;
        for(int i=0; i<str.length(); i++) {
            if(str[i]>=48 && str[i]<=57)
                sum = 10*sum + (str[i]-48);
            else if(str[i] == 32 || str[i] == 59) {
                v.push_back(sum);
                sum = 0;
            }
        }
        target = sum;
        ans[k] = subsetSum(v, target);
    }

    for(int i=0; i<n; i++) {
        if(ans[i])
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }

    return 0;
}
