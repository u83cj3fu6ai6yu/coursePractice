%{

	#include <stdio.h>
	#include <string.h>
	#define N 27
	int yylex(void);
	void yyerror(const char *message);

	int i, j, key = 1, Par = 0, key2 = 1, totalcoef = 1;
	int count[N][N], mark[N][N], markPar[N][N];

	void ResetMark() {
		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) {
				mark[i][j] = 0;
			}
		}
	}

	void ResetMarkPar() {
		for(i=0; i<N; i++) {
			for(j=0; j<N; j++) {
				markPar[i][j] = 0;
			}
		}
	}

	void print() {
		for (i=1; i<N; i++) {
			if (count[i][0]!=0) {
				printf("%c %d\n", (i-1+'A'), count[i][0]);
			}
			for (j=1; j<N; j++) {
				if (count[i][j]!=0) {
					printf("%c%c %d\n", (i-1+'A'), (j-1+'a'), count[i][j]);
				}       
			}
		}
	}

%}


%union {
	int ival;
	char* word;
}


%token<ival> INUMBER
%token<word> UPCASE
%token<word> LOCASE

%type<ival> coef
%type<word> elems
%type<word> elem
%type<word> exprs
%type<word> expr

%%

line    : exprs '-' '>' { key = -1; } exprs	{}
        ;

exprs   : expr '+' exprs	{}
        | expr			{}
        ;

expr    : coef elems     {
		for (i=1; i<N; i++) for (j=0; j<N; j++) {
			if (markPar[i][j] != 0) {
				mark[i][j] += markPar[i][j] * (totalcoef);
			}
		}
		ResetMarkPar();

		for (i=1; i<N; i++) {
			for (j=0; j<N; j++) {
				if (mark[i][j] != 0) {
					count[i][j] += key * mark[i][j] * ($1);
				}
			}
		}
		ResetMark();
        }
        ;

coef    : INUMBER       { $$ = $1; }
        |               { $$ = 1; }
        ;

elems   : elem elems  {}
        | elem       {}
        ;

elem     : UPCASE coef            {
		int up = ($1)[0] - 'A' + 1;

		if (Par==1) {
			markPar[up][0] = $2;
		}
		else {
			mark[up][0] += ($2);
		}
        }
        | UPCASE LOCASE coef      {
		int up = ($1)[0]-'A' + 1;
		int lo = ($2)[0]-'a' + 1;

		if (Par==1) {
			markPar[up][lo] = $3;
		}
		else {
			mark[up][lo] += ($3);
		}
        }
        | '(' { Par = 1; }  elems ')' { Par = 0; } coef     { 
            totalcoef *= $6;
         }
        ;

%%

void yyerror (const char *message) {
	printf ("Invalid format\n");
	key2 = 0;	
}

int main(int argc, char *argv[]) {

	for (i=0; i<N; i++) {
		for (j=0; j<N; j++) {
			count[i][j] = 0;
			mark[i][j] = 0;
			markPar[i][j] = 0;
		}
	}

        yyparse();

	if(key2) {
		print();
	}

        return 0;
}
