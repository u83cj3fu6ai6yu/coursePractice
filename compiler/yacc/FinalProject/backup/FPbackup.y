%{

#include <stdio.h>
#include <string.h>
int yylex(void);
void yyerror(const char *message);

int top = -1;
char st[100];
int equal = 1;
%}

%union {
	char* ch;
	int ival;
}

%token<ch> printnum;
%token<ch> printbool;
%token<ival> number;
%token<ival> bool_val;

%type<ival> EXP;
%type<ival> EXPS;
%type<ival> PRINT_STMT;
%type<ival> STMT;
%type<ival> STMTS;
%type<ival> NUM_OP;
%type<ival> PLUS;
%type<ival> MINUS;
%type<ival> MULTIPLY;
%type<ival> DIVIDE;
%type<ival> MODULUS;
%type<ival> GREATER;
%type<ival> SMALLER;
%type<ival> EQUAL;
%type<ival> LOGICAL_OP;
%type<ival> AND_OP;
%type<ival> OR_OP;
%type<ival> NOT_OP;
%type<ival> IF_EXP;
%type<ival> TEST_EXP;
%type<ival> THEN_EXP;
%type<ival> ELSE_EXP;

%%

PROGRAM		: STMTS					{ return(0); }
		;

STMTS		: STMT STMTS				{}
		| STMT					{}
		;

STMT		: EXP					{}
		//| DEF_STMT
		| PRINT_STMT				{}
		;

PRINT_STMT	: '(' printnum EXP ')'		{ printf("%d\n", $3); }
		| '(' printbool EXP ')'		{ if($3) printf("#t\n"); else printf("#f\n"); }
		;

EXPS		: EXP EXPS				{ if(st[top] == '+') $$ = $1 + $2; else if(st[top] == '*') $$ = $1 * $2; else if(st[top] == '&') $$ = $1 & $2; else if(st[top] == '|') $$ = $1 | $2; else if(st[top] == '=') {if($1 != $2) equal = 0; $$ = $1; } }
		| EXP					{ $$ = $1; }
		;

EXP		: bool_val				{ $$ = $1; }
		| number				{ $$ = $1; }
		| NUM_OP				{ $$ = $1; }
		| LOGICAL_OP				{ $$ = $1; }
		| IF_EXP				{ $$ = $1; }
		;

NUM_OP		: PLUS					{ $$ = $1; }
		| MINUS					{ $$ = $1; }
		| MULTIPLY				{ $$ = $1; }
		| DIVIDE				{ $$ = $1; }
		| MODULUS				{ $$ = $1; }
		| GREATER				{ $$ = $1; }
		| SMALLER				{ $$ = $1; }
		| EQUAL					{ $$ = $1; }
		;

PLUS		: '(' '+' {st[++top] = '+';} EXP EXPS ')'	{ top--; $$ = $4 + $5; }
		;

MINUS		: '(' '-' EXP EXP ')'				{ $$ = $3 - $4; }
		;

MULTIPLY	: '(' '*' {st[++top] = '*';} EXP EXPS ')'	{ top--; $$ = $4 * $5; }
		;

DIVIDE		: '(' '/' EXP EXP ')'				{ $$ = $3 / $4; }
		;

MODULUS		: '(' 'm' 'o' 'd' EXP EXP ')'			{ $$ = $5 % $6; }
		;

GREATER		: '(' '>' EXP EXP ')'			{ if($3 > $4) $$ = 1; else $$ = 0; }
		;

SMALLER		: '(' '<' EXP EXP ')'			{ if($3 < $4) $$ = 1; else $$ = 0; }
		;

EQUAL		: '(' '=' {st[++top] = '='; equal = 1;} EXP EXPS ')'	{ top--; if($4 == $5 && equal == 1) $$ = 1; else $$ = 0; }
		;

LOGICAL_OP	: AND_OP				{ $$ = $1; }
		| OR_OP					{ $$ = $1; }
		| NOT_OP				{ $$ = $1; }
		;

AND_OP		: '(' 'a' 'n' 'd' {st[++top] = '&';} EXP EXPS ')'	{ top--; $$ = $6 && $7; }
		;

OR_OP		: '(' 'o' 'r' {st[++top] = '|';} EXP EXPS ')'		{ top--; $$ = $5 || $6; }
		;

NOT_OP		: '(' 'n' 'o' 't' EXP ')'				{ if($5) $$ = 0; else $$ = 1; }
		;

IF_EXP		: '(' 'i' 'f' TEST_EXP THEN_EXP ELSE_EXP ')'		{ if($4) $$ = $5; else $$ = $6; }
		;

TEST_EXP	: EXP			{ $$ = $1; }
		;

THEN_EXP	: EXP			{ $$ = $1; }
		;

ELSE_EXP	: EXP			{ $$ = $1; }
		;

%%

void yyerror (const char *message) {
	printf ("syntax error\n");
}

int main(int argc, char *argv[]) {

        yyparse();

        return 0;
}
