// Hungarian algorithm
// hw9 of algorithm
// 12/20/2016

#include <iostream>
#include <string.h>
#include <vector>
#include <map>
using namespace std;

struct s {
	int x, y;
};

int Hungarian(int M) {
	// set the 2D array also find out the biggest #
	int origin[M][M] = {}, calculate[M][M] = {}, max = 0;
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++) {
			cin>>origin[i][j];
			calculate[i][j] = origin[i][j];
			if(max < calculate[i][j])
				max = calculate[i][j];
		}
	// declare a vector to store the x, y index of point whose element is zero
	vector<struct s> zero;
	struct s target;
	// declare a map to store how many line at least to cover element zero 
	map<int, int> rowmap, colmap;
	int line, duplicate;
	// subtract each element from biggest # also find out the smallest # of each row
	int rowmin[M];
	memset(rowmin, 2147483647, sizeof(rowmin[0]));
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++) {
			calculate[i][j] = max - calculate[i][j];
			if(rowmin[i] > calculate[i][j])
				rowmin[i] = calculate[i][j];
		}
	// row subtraction, find out the smallest # of each col, also store index of point whose element is zero by vector
	int colmin[M];
	memset(colmin, 2147483647, sizeof(colmin[0]));
	for(int i=0; i<M; i++)
		for(int j=0; j<M; j++) {
			calculate[i][j] -= rowmin[i];
			if(colmin[j] > calculate[i][j])
				colmin[j] = calculate[i][j];
			if(calculate[i][j] == 0) {
				target.x = i;
				target.y = j;
				zero.push_back(target);
			}
		}
	// 判斷最少幾條線可以覆蓋0(這裡有邏輯上錯誤還沒解決) 
	line = 0, duplicate = 0;
	for(int i=0; i<zero.size; i++) {
		if(rowmap.find(zero[i].x) == rowmap.end() && colmap.find(zero[i].y) == colmap.end()) {
			rowmap.insert(pair<int, int>(zero[i].x, 1));
			rowmap.insert(pair<int, int>(zero[i].x, 1));
			line++;
		}
		else {
			if(colmap.find(zero[i].y) != colmap.end()) {
				colmap.insert(pair<int, int>(zero[i].y), 1);
				line++;
				duplicate++;
			}
			else if(rowmap.find(zero[i].x) != rowmap.end()) {
				rowmap.insert(pair<int, int>(zero[i].x, 1));
				line++;
				duplicate++;
			}
		}
	}
}

int main() {
	int N, M;
	cin>>N;
	
	int ans[N] = {};
	for(int i=0; i<N; i++) {
		cin>>M;
		ans[i] = Hungarian(M);
	}
} 
