%{
#include "prob6A.tab.h"
int where = 0;
%}
%%

\n	{ where += yyleng; return(0); /* EOF */ }
[ \t]+	{ where += yyleng; /* do nothing */ }
[0-9]+	{ where += yyleng; yylval.val = atoi(yytext); return(NUMBER); }
"+"	{ where += yyleng; yylval.op = where; return(PLUS); }
"-"	{ where += yyleng; yylval.op = where; return(MINUS); }
"*"	{ where += yyleng; yylval.op = where; return(MULTIPLY); }
"^"|"T"|"("|")"|","|"["|"]"	{ where += yyleng; return(yytext[0]); }
.	{ where += yyleng; return(yytext[0]); }

%%
