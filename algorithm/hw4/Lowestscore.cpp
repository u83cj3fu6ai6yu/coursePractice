// Lowest score
// hw4 of algorithmics
// 10/18/2016

#include<iostream>
using namespace std;

void ThreeLowestScore(int k, int *score, int &num, char *ans) {
	int b = 0; // store which index is the begin of class B
	while(true) {
		if(score[b] > score[b+1]) {
			b++;
			break;
		}
		else
			b++;
	}
	
	int count=0, a=0, bstart = b;
	while(count<3) {
		if(a>=bstart) {
			ans[num] = 'B';
			b++;
			count++;
			num++;
		}
		else if(b>=k) {
			ans[num] = 'A';
			a++;
			count++;
			num++;
		}
		else {
			if(score[a] >= score[b]) {
				ans[num] = 'B';
				b++;
				count++;
				num++;
			}
			else {
				ans[num] = 'A';
				a++;
				count++;
				num++;
			}
		}
	}
}

int main() {
	int data; // store # of testing data
	cin>>data;
	
	int k, score[100000] = {}; // k store # of students
	char ans[3*data];
	int num = 0; // store which index to keep storing answer
	for(int i=0; i<data; i++) {
		cin>>k;
		for(int j=0; j<k; j++)
			cin>>score[j];
		ThreeLowestScore(k, score, num, ans);
	}
	
	// print the answer
	for(int i=0; i<3*data; i=i+3)
		cout<<ans[i]<<ans[i+1]<<ans[i+2]<<endl;
}
