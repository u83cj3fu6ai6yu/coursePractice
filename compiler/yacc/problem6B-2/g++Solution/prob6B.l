%{
#include "prob6B.tab.h"
int key = 1;
%}
%%

\n	{ return(0); /* EOF */ }
[ \t]+	{ /* do nothing */ }
[A-Z0-9()]+	{ yylval.str = strdup(yytext);  return(words); }
"+"|"-"|">"	{ if(yytext[0] == '>') { key = -1; } return(yytext[0]); }
.	{ return(yytext[0]); }

%%
