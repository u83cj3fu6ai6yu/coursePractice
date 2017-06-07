%{
    #include <stdio.h>
    #include <string.h>
    #define M 27
    int yylex(void);
    void yyerror(const char *message);

    int sign=1, openPar=0, key = 1, totalcoef = 1;
    int count[M][M], mark[M][M], markPar[M][M];
    int i, j;

    void ResetMark() {
        for (i=0; i<M; i++) {
            for (j=0; j<M; j++) {
                //count[i][j] = 0;
                mark[i][j] = 0;
            }
        }
    }

    void ResetMarkPar() {
        for (i=0; i<M; i++) {
            for (j=0; j<M; j++) {
                //count[i][j] = 0;
                markPar[i][j] = 0;
            }
        }
    }

%}
%union{
int ival;
char* word;
}
%token<ival> INUMBER
%token<word> BWORD
%token<word> SWORD

%type<ival> coef
%type<word> elms
%type<word> elm
%type<word> expr
%type<word> exprs
%%
line    : exprs '-' '>' {sign=-1; } exprs     {}
        ;

exprs   : expr '+' exprs    {}
        | expr          {}
        ;

expr    : coef elms     {
            //printf("coef: %d\n", $1);
            // mul marks, $1, $3
	    for (i=1; i<M; i++) for (j=0; j<M; j++) {
                if (markPar[i][j]!=0) {
                    mark[i][j] += markPar[i][j]*(totalcoef);
                }
            }

            ResetMarkPar();
            for (i=1; i<M; i++) for (j=0; j<M; j++) {
                if (mark[i][j]!=0) {
                    count[i][j] += 1*sign*mark[i][j]*($1);
                }
            }

            ResetMark();
        }
        ; 

coef    : INUMBER       {$$ = $1;}
        |               {$$ = 1;}
        ;

elms    : elm elms  {}
        | elm       {}
        ;

elm     : BWORD coef            {
            //printf("%s %d\n", $1, $2);
            int b = ($1)[0]-'A'; b+=1;
            //printf("%d\n", b);
            
            if (openPar==1) markPar[b][0] = $2;
            else mark[b][0] += ($2);
            
        }
        | BWORD SWORD coef      { 
             //printf("%s%s %d\n", $1, $2, $3); 
             int b = ($1)[0]-'A'; b+=1;
             int s = ($2)[0]-'a'; s+=1;
             //printf("%d %d\n", b, s);
             
             if (openPar==1) markPar[b][s] = $3;
             else mark[b][s] += ($3);
             
        }
        | '(' {openPar=1;}  elms ')' {openPar=0;} coef     { 
            totalcoef *= $6;
         }
        ;

%%

void yyerror (const char *message) {
    printf ("Invalid format\n");
    key = 0;
}

int main(int argc, char *argv[]) {
    // init
    for (i=0; i<M; i++) {
        for (j=0; j<M; j++) {
            count[i][j] = 0;
            mark[i][j] = 0;
            markPar[i][j] = 0;
        }
    }
    
    yyparse();
    //printf("------\n");

    if(key) {
	    for (i=1; i<M; i++) {
		if (count[i][0]!=0) {
		    printf("%c %d\n", (i-1+'A'), count[i][0]);
		}
		for (j=1; j<M; j++) {
		    if (count[i][j]!=0) {
		        printf("%c%c %d\n", (i-1+'A'), (j-1+'a'), count[i][j]);
		    }       
		}
	    }
    }

    
    return 0;
}
