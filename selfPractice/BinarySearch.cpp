// Binary Search

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

int bs(int *arr, int len, int searchnum) {
	int left = 0, right = len-1, middle;
	while(left <= right) {
		middle = (left + right)/2;
		if(arr[middle] < searchnum)
			left = middle + 1;
		else if(arr[middle] > searchnum)
			right = middle - 1;
		else
			return middle;
	}
	return -1;
}

int main() {
	int arr[10] = {897,52,13,10,234,853,357312,89,351,0};
	int len = sizeof(arr)/sizeof(arr[0]);
	ss(arr, len);
	for(int i=0; i<len; i++)
		cout<<arr[i]<<"  ";
	cout<<endl;
	
	int index = bs(arr, len, 896);
	if(index >= 0)
		cout<<"Found! Index is "<<index;
	else
		cout<<"Not found";
	return 0;
}
