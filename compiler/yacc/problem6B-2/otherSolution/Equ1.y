%{
    #include <stdio.h>
    #include <string.h>

    int yylex(void);
    void yyerror(const char* message);
    int differentN[26][27];
    void print();
    void combine(int**, int**);
    void diff(int**, int**, int**);
    void multiply(int**, int);
    void init(int** );

%}

%union {
    int ival;
    int coms[26][27];
}


%token <ival> ELEMENT
%token <ival> INUMBER
%type <coms> expr
%type <coms> chem

%%
line    : expr '-' '>' expr  { diff($1,$4,differentN); print(); }
        ;

expr	: expr '+' expr {init($$);combine($1,$3);combine($$,$1);}
	| INUMBER chem	{init($$);multiply($2, $1);combine($$,$2);}
	| chem { init($$);combine($$, $1);}	
	;

chem	: '(' chem ')' INUMBER	{init($$);multiply($2,$4); combine($$,$2);}
	| '(' chem ')'	{init($$) ; combine($$,$2);}
	| chem chem {init($$);combine($1,$2);combine($$,$1);}
	| ELEMENT INUMBER {init($$);$$[($1/100)][($1%100)]+=$2;}
	| ELEMENT {init($$);$$[($1/100)][($1%100)]++;}
	;

%%
void yyerror (const char* message) {
        printf("Invalid format\n");
}
void init(int** a) {
	for(int i =0; i<26; i++)
	{
	    for(int j=0;j<27;j++)
	    {

		*((int *) a + 27 * i + j) = 0;
	    }
	}
}

void print()
{
	int count=0;
	for(int i =0; i<26 ; i++)
    {
	for(int j = 0; j<27; j++)
	{
	   if(differentN[i][j] != 0)
	   {
		  count++;
	   }
     }
    }
    for(int i =0; i<26 ; i++)
    {
	for(int j = 0; j<27; j++)
	{
	   if(differentN[i][j] != 0)
	   {
		char e1 = (char) (i+64);
		char e2 = (char) (j+96);
		if(e2==96) {
			e2=0;
		}		
		if(e2 != 0) {
			printf("%c%c %d",e1,e2,differentN[i][j]);
		}
		else {
			printf("%c %d",e1,differentN[i][j]);
		}
		printf("\n");
		/*if(count-1>0)
		{
		//	printf("count: %d\n",count);
			printf("\n");
			count--;
		}*/
	   }
        }
    }
}
void diff(int** a ,int** b,int** c) 
{
	for(int i =0; i<26 ; i++)
	{
	    for(int j = 0; j<27; j++)
	    {
	       //c[i][j] = a[i][j] - b[i][j];
		*((int *) c + 27 * i + j) = *((int *) a + 27 * i + j) - *((int *) b + 27 * i + j);
            }
	}
}
void combine(int** a, int** b)
{
   for(int i = 0; i<26;i++)
   {
	for(int j = 0; j<27; j++)
	{
	   //a[i][j] = a[i][j] + b[i][j];
	   *((int *) a + 27 * i + j) = *((int *) a + 27 * i + j) + *((int *) b + 27 * i + j);
	}
   }
}

void multiply(int** k, int m)
{
	for(int i=0;i<26;i++)
	{
	    for(int j = 0; j<27; j++)
	    {
	       //k[i][j] *= m;
		*((int *) k + 27 * i + j) *= m;
	    }
	}
}
int main(int argc, char *argv[]) {
            yyparse();
            return 0;
}
