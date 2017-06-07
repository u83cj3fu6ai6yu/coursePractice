// SelectionSort

#include<iostream>
using namespace std;

void ss(int *arr, int len) {
	int min;
	for(int i=0; i<len-1; i++) {
		min = i;
		for(int j=i+1; j<len; j++) {
			if(arr[min] > arr[j])
				min = j;
		}
		swap(arr[i], arr[min]);
	}
}

int main() {
	int arr[10] = {897,52,13,10,234,853,357312,89,351,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	ss(arr, len);
	for(int i=0; i<len; i++)
		cout<<arr[i]<<"  ";
	
	return 0;
}
