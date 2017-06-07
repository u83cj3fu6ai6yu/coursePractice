// Packets
// hw5 of algorithmics
// 10/25/2016

#include<iostream>
using namespace std;

int solution(int a, int b, int c, int d, int e, int f) {
	int num = 0, area; // # of box
	// for 6*6 object
	num += f;
	// for 5*5 object
	num += e;
	a -= 11*e;
	if(a < 0) a = 0;
	// for 4*4 object
	num += d;
	if(20*d >= 4*b) {
		area = 20*d - 4*b;
		b = 0;
		a -= area;
		if(a < 0) a = 0;
	}
	else {
		b -= 20*d/4;
	}
	// for 3*3 object
	num += c/4;
	if(c%4) {
		num++;
		if(c%4 == 1) {
			if(b >= 5) {
				b -= 5;
				area = 7;
				a -= area;
				if(a < 0) a = 0;
			}
			else {
				area = 27 - 4*b;
				a -= area;
				if(a < 0) a = 0;
			}
		}
		else if(c%4 == 2) {
			if(b >= 3) {
				b -= 3;
				area = 6;
				a -= area;
				if(a < 0) a = 0;
			}
			else {
				area = 18 - 4*b;
				a -= area;
				if(a < 0) a = 0;
			}
		}
		else if(c%4 == 3) {
			if(b >= 1) {
				b -= 1;
				area = 5;
				a -= area;
				 if(a < 0) a = 0;
			}
			else {
				area = 9;
				a -= area;
				if(a < 0) a = 0;
			}
		}
	}
	// for 2*2 object
	num += b/9;
	if(b%9) {
		num++;
		area = 36 - 4*(b%9);
		a -= area;
		if(a < 0) a = 0;
	}
	// for 1*1 object
	num += a/36;
	if(a%36) num++;
	
	return num;
}

int main() {
	int a, b, c, d, e, f, sum, i=0, ans[1000] = {};
	
	while(true) {
		cin>>a>>b>>c>>d>>e>>f;
		if( !(a+b+c+d+e+f) )
			break;
		else {
			ans[i] = solution(a,b,c,d,e,f);
			i++;
		}
	}
	
	i=0;
	while(ans[i]) {
		cout<<ans[i]<<endl;
		i++;
	}
}
