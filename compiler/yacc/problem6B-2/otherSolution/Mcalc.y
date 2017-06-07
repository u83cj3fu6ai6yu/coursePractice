%{
    #include <stdio.h>
    #include <string.h>
    int yylex(void);
    void yyerror(const  int message);
    extern int count;
    extern int op;
%}

%union {
    int ival;
    struct M{
        int a, b;
    }Ma;    
	int pos;
}
%locations 
%token <ival> INUMBER
%token <pos> PLUS
%token <pos> MINUS
%token <pos> TIMES
%type <Ma> expr
%type <Ma> matrix
%left PLUS MINUS
%left TIMES

%%
line    : expr  { printf("Accepted"); }
        ;

expr    : expr PLUS expr	{ if(($1.a==$3.a)&&($1.b==$3.b)){$$.a=$1.a; $$.b=$3.b;}else{yyerror($2);return(0);} }
        | expr MINUS expr	{ if(($1.a==$3.a)&&($1.b==$3.b)){$$.a=$1.a; $$.b=$3.b;}else{yyerror($2);return(0);} }
        | expr TIMES expr	{ if($1.b==$3.a){$$.a=$1.a; $$.b=$3.b;}else{yyerror($2);return(0);} }
	| '(' expr ')'	{ $$.a=$2.a; $$.b=$2.b; }
	| expr '^' 'T' 	{ $$.a=$1.b; $$.b=$1.a; }
	| matrix	{ $$.a=$1.a; $$.b=$1.b; }
        ;

matrix   : '[' INUMBER ',' INUMBER ']'	{ $$.a=$2; $$.b=$4; }
	;

%%
void yyerror (const int message) {
        printf("Semantic error on col %d\n", message);
}
/*void yyerror(char *s)
{
  //va_list ap;
  //va_start(ap, s);
  if(yylloc.first_line)
    fprintf(stderr, "%d.%d-%d.%d: error: ", yylloc.first_line, yylloc.first_column,
        yylloc.last_line, yylloc.last_column);
  //vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}
void lyyerror(YYLTYPE t, char *s)
{
 // va_list ap;
 // va_start(ap, s);
  if(t.first_line)
    fprintf(stderr, "%d.%d-%d.%d: error: ", t.first_line, t.first_column,
        t.last_line, t.last_column);
  //vfprintf(stderr, s, ap);
  fprintf(stderr, "\n");
}*/
int main(int argc, char *argv[]) {
            yyparse();
            return 0;
}
