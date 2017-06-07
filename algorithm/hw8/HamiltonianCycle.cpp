// Hamiltonian Cycle
// hw8 of algorithm
// 12/13/2016

#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <sstream>
#define MAX_SIZE 20
using namespace std;

bool adj[MAX_SIZE][MAX_SIZE] = {};

void Hamiltonian(int &answer, int* record, int big, int pos, int num) {
    if(num == big && adj[pos][1]) {
            answer = 1;
    }
    else if(num != big) {
        for(int i=1; i<=big; i++) {
            if(adj[pos][i] && record[i] == 0) {
                record[i] = 1;
                num++;
                Hamiltonian(answer, record, big, i, num);
                record[i] = 0;
                num--;
            }
        }
    }
}

int main() {
    int dataset, edgenum, head, tail, big;
    string str;
    getline(cin, str);
    dataset = str[0] - 48;

    int ans[dataset] = {};
    for(int i=0; i<dataset; i++) {
        getline(cin, str);
        edgenum = str[0] - 48;
        big = 0;//the number of vertice
        memset(adj, 0, sizeof(adj[0][0]) * MAX_SIZE * MAX_SIZE);
        for(int j=0; j<edgenum; j++) {
            getline(cin, str);
            int c = 0, index = 0;
            while(c!=2) {
                if(str[index]>=48 && str[index]<=57 && c == 0) {
                    head = str[index] - 48;
                    c++;
                }
                else if(str[index]>=48 && str[index]<=57 && c == 1) {
                    tail = str[index] - 48;
                    c++;
                }
                index++;
            }
            adj[head][tail]=1;
            adj[tail][head]=1;
            if(big < head)
				big = head;
			if(big < tail)
				big = tail;
        }
        int record[big+1] = {}, answer = 0;
        record[1] = 1;
        Hamiltonian(answer, record, big, 1, 1);
        ans[i] = answer;
    }
    for(int i=0; i<dataset; i++) {
        if(ans[i])
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }

    return 0;
}
