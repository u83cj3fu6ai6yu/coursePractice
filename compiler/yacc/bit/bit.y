%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);
extern int key;

%}
%union {
	int ival;
}

%token <ival> INUMBER
%type <ival> exprs

%%

line	: INUMBER			{ printf("syntax error"); return(0); }
	| '~' ' ' INUMBER ' ' INUMBER	{ printf("syntax error"); return(0); }
	| exprs				{ printf("%d", $1); return(0); }
	;

exprs	: '&' ' ' exprs ' ' exprs	{ $$ = ($3 & $5); }
	| '|' ' ' exprs ' ' exprs	{ $$ = ($3 | $5); }
	| '^' ' ' exprs ' ' exprs	{ $$ = ($3 ^ $5); }
	| '~' ' ' exprs			{ $$ = (31 - $3); }
	| '<' '<' ' ' exprs ' ' exprs	{ $$ = ($4 << $6); }
	| '>' '>' ' ' exprs ' ' exprs	{ $$ = ($4 >> $6); }
	| INUMBER			{ if($1 > 31 || $1 < 0) {printf("integer out of range"); return(0);} else {$$ = $1;} }
	;

%%

void yyerror (const char *message) {
	if(key == 0)
		printf ("syntax error");
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
