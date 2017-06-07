%{
#include "Mcalc.tab.h"

int yycolumn = 1;
int count=1;
int op=0;

%}

%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ count+=yyleng; }
[0-9]+	{ count+=yyleng; yylval.ival = atoi(yytext); return(INUMBER);}
"+"		{yylval.pos = count; count+=yyleng; return(PLUS);}
"-"		{yylval.pos = count; count+=yyleng; return(MINUS);}
"*"		{yylval.pos = count; count+=yyleng; return(TIMES);}
"^"|"T"|"("|")"|"["|"]"|","	{ count+=yyleng; return(yytext[0]); }
.	{ count+=yyleng; return(yytext[0]); }

%%
