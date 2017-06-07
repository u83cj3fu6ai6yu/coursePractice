// 8puzzle with full-width number input
// hw10 of algorithm
// 12/27/2016

#include <iostream>
#include <string.h>
using namespace std;

void evaluate(string puzzle[3][3]) {
    int evalue = 0;
    string goal[3][3] = { {"¢°", "¢±", "¢²"}, {"¢·", "¡@", "¢³"}, {"¢¶", "¢µ", "¢´"} };

    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            cout<<puzzle[i][j];
            if(puzzle[i][j] != goal[i][j])
                evalue++;
        }
        cout<<endl;
    }

    cout<<evalue<<endl;
}

int main() {
    int spacei, spacej;
    string puzzle[3][3];
    string str;
    for(int i=0; i<3; i++) {
        getline(cin, str);
        for(int j=0; j<3; j++) {
            puzzle[i][j] = str.substr(2*j, 2);
            if(puzzle[i][j] == "¡@") {
                spacei = i;
                spacej = j;
            }
        }
    }

    if(spacei-1 >= 0) {
        swap(puzzle[spacei][spacej], puzzle[spacei-1][spacej]);
        evaluate(puzzle);
        swap(puzzle[spacei][spacej], puzzle[spacei-1][spacej]);
    }
    if(spacej+1 <= 2) {
        swap(puzzle[spacei][spacej], puzzle[spacei][spacej+1]);
        evaluate(puzzle);
        swap(puzzle[spacei][spacej], puzzle[spacei][spacej+1]);
    }
    if(spacei+1 <= 2) {
        swap(puzzle[spacei][spacej], puzzle[spacei+1][spacej]);
        evaluate(puzzle);
        swap(puzzle[spacei][spacej], puzzle[spacei+1][spacej]);
    }
    if(spacej-1 >= 0) {
        swap(puzzle[spacei][spacej], puzzle[spacei][spacej-1]);
        evaluate(puzzle);
        swap(puzzle[spacei][spacej], puzzle[spacei][spacej-1]);
    }

    return 0;
}
