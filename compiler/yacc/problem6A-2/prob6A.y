%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

%}
%union {
	int val;
	struct{
		int lval;
		int rval;
	} s;
	int op;
}

%token <val> NUMBER
%token <op> PLUS
%token <op> MINUS
%token <op> MULTIPLY
%type <s> expr
%type <val> left
%type <val> right
%left PLUS MINUS
%left MULTIPLY

%%

line	: expr			{ printf("Accepted"); }
	;

expr    : expr PLUS expr	{ if($1.lval == $3.lval && $1.rval == $3.rval) {$$.lval = $1.lval; $$.rval = $1.rval;} else {printf("Semantic error on col %d\n", $2); return(0);} }
	| expr MINUS expr	{ if($1.lval == $3.lval && $1.rval == $3.rval) {$$.lval = $1.lval; $$.rval = $1.rval;} else {printf("Semantic error on col %d\n", $2); return(0);} }
        | expr MULTIPLY expr	{ if($1.rval == $3.lval) {$$.lval = $1.lval; $$.rval = $3.rval;} else {printf("Semantic error on col %d\n", $2); return(0);} }
        | expr '^' 'T'         	{ $$.lval = $1.rval; $$.rval = $1.lval; }
        | '(' expr ')'          { $$.lval = $2.lval; $$.rval = $2.rval; }
	| '[' left ',' right ']'{ $$.lval = $2; $$.rval = $4; }
	;

left	: NUMBER		{ $$ = $1; }
	;

right	: NUMBER		{ $$ = $1; }
	;

%%

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
