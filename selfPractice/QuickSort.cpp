// QuickSort
// algorithmics Divide&Conquer
// 11/7/2016

#include<iostream>
using namespace std;

int len;

void quicksort(int *arr, int lb, int rb) {
	if(lb < rb) {
		int p = arr[rb]; // p is pivot
		int l = lb, r = rb-1;

		while(true) {
			while(arr[l] < p)
				l++;
			while(arr[r] >= p && r != lb)
				r--;
			if(l < r) {
				swap(arr[l], arr[r]);
				for(int k=0; k<len; k++)
                    cout<<arr[k]<<'\t';
                cout<<endl;
			}
			else
				break;
		}

        if(arr[rb] != arr[l]) {
            swap(arr[rb], arr[l]);
            for(int k=0; k<len; k++)
                cout<<arr[k]<<'\t';
            cout<<endl;
        }
		quicksort(arr, lb, l-1);
		quicksort(arr, l+1, rb);
	}
}

int main() {
	int arr[] = {85, 24, 63, 50, 17, 51, 96, 58};
	len = sizeof(arr)/sizeof(arr[0]);
	cout<<len<<endl;
	quicksort(arr, 0, len-1);
	/*for(int i=0; i<len; i++)
		cout<<arr[i]<<'\t';*/
}
