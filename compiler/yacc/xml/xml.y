%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

%}
%union {
	int ival;
}

%type <ival> exprs

%%

line	: 't''r''u''e''/'			{ printf("true\n"); return(0); }
	| 'f''a''l''s''e''/'			{ printf("false\n"); return(0); }
	| exprs					{ if($1) {printf("true\n");} else {printf("false\n");} return(0); }
	;

exprs	: 'a''n''d' expr exprs '/''a''n''d'	{ $$ = ($4 & $5); }
	| 'o''r' expr exprs '/''o''r'		{ $$ = ($3 | $4); }
	| 'n''o''t' expr '/''n''o''t'		{ if($4) $$ = 0; else $$ = 1; }
	| expr exprs				{}
	|					{}
	;

expr	: 't''r''u''e''/'			{ $$ = 1; }
	| 'f''a''l''s''e''/'			{ $$ = 0; }
	;

%%

void yyerror (const char *message) {
	printf ("syntax error");
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
