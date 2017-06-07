%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

%}
%union {
	int ival;
}

%token <ival> INUMBER
%type <ival> exprs

%%

line	: 't''r''u''e'			{ if($1) {printf("true\n");} else {printf("false\n");} return(0); }
	| exprs				{ if($1) {printf("true\n");} else {printf("false\n");} return(0); }
	;

exprs	: 'a''n''d' exprs exprs '/''a''n''d'		{ $$ = ($2 & $3); }
	| 'o''r' exprs exprs '/''o''r'		{ $$ = ($2 | $3); }
	| 'n''o''t' INUMBER '/''n''o''t'		{ if($1) $$ = 0; else $$ = 1; }
	| INUMBER			{ $$ = $1; }
	|				{}
	;

%%

void yyerror (const char *message) {
	printf ("syntax error");
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
