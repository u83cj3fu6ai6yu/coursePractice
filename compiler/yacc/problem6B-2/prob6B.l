%{
#include "prob6B.tab.h"
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.ival = atoi(yytext); return(INUMBER); }
[A-Z]	{ yylval.word = strdup(yytext);  return(UPCASE); }
[a-z]	{ yylval.word = strdup(yytext);  return(LOCASE); }
"+"|"("|")"	{ return(yytext[0]); }
.	{ return(yytext[0]); }
