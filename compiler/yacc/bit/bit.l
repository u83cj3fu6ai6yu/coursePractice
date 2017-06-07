%{
#include "bit.tab.h"
int key = 0;
%}
%%

\n	{ return(0); /* EOF */ }
[ ]	{ return(yytext[0]); }
[+-]?[0-9]+	{ if((yyleng >= 3) || (yytext[0] == '-')) { key = 1; printf("integer out of range"); return(0);} else {yylval.ival = atoi(yytext); return(INUMBER);} }
"&"|"|"|"^"|"~"|"<"|">"	{ return(yytext[0]); }
.	{ return(yytext[0]); }

%%
