// find the # between L & U which has most divisors
// hw11 of algorithm
// 1/3/2017

#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

struct s {
    int L, U, dividend, num;
};

int Divisors(int j) {
    int c = sqrt(j);
    if(c == sqrt(j))
        c = -1;
    else
        c = 0;

    for(int k=1; k<sqrt(j); k++) {
        if(j%k == 0)
            c += 2;
    }

    return c;
}

void Dividend(int L, int U, struct s *ans, int i) {
    ans[i].L = L;
    ans[i].U = U;

    int dividend, maxnum = 0, num;
    for(int j=L; j<=U; j++) {
        num = Divisors(j);
        if(num > maxnum) {
            dividend = j;
            maxnum = num;
        }
    }

    ans[i].dividend = dividend;
    ans[i].num = maxnum;
}

int main() {
    int N;
    cin>>N;

    int L, U;
    struct s ans[N];
    for(int i=0; i<N; i++) {
        cin>>L>>U;
        Dividend(L, U, ans, i);
    }

    for(int i=0; i<N; i++)
        printf("Between %d and %d, %d has a maximum of %d divisors.\n", ans[i].L, ans[i].U, ans[i].dividend, ans[i].num);
}
