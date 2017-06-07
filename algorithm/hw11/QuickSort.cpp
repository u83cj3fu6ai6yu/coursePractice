// QuickSort
// hw11 of algorithm
// 1/3/2017

#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
using namespace std;

void quicksort(vector<int> &arr, int lb, int rb) {
    if(lb >= rb)
        ;
    else {
        int p = arr[rb]; // p is pivot
        int l = lb, r = rb-1;

        while(true) {
            while(arr[l] < p)
                l++;
            while(arr[r] >= p && r != lb)
                r--;
            if(l < r) {
                swap(arr[l], arr[r]);
                for(int k=0; k<arr.size()-1; k++)
                    cout<<arr[k]<<" ";
                cout<<arr[arr.size()-1]<<endl;
            }
            else
                break;
        }

        if(arr[rb] != arr[l]) {
            swap(arr[rb], arr[l]);
            for(int k=0; k<arr.size()-1; k++)
                cout<<arr[k]<<" ";
            cout<<arr[arr.size()-1]<<endl;
        }

        quicksort(arr, lb, l-1);
        quicksort(arr, l+1, rb);
    }
}

int main() {
    int num;
	vector<int> arr;
    string str;
    stringstream ss;

    getline(cin, str);
    ss<<str;
    while(!ss.eof()) {
        ss>>num;
        arr.push_back(num);
    }

    for(int k=0; k<arr.size()-1; k++)
        cout<<arr[k]<<" ";
    cout<<arr[arr.size()-1]<<endl;

	quicksort(arr, 0, arr.size()-1);

	return 0;
}
