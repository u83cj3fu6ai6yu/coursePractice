%{
#include "xml.tab.h"
%}


%%

[andortuefls/]		{ return(yytext[0]); }
[ \t\n]			{}
"<and>"			{ yylval.ch = strdup(yytext); return(and); }
"</and>"		{ yylval.ch = strdup(yytext); return(eand); }
"<or>"			{ yylval.ch = strdup(yytext); return(or); }
"</or>"			{ yylval.ch = strdup(yytext); return(eor); }
"<not>"			{ yylval.ch = strdup(yytext); return(not); }
"</not>"		{ yylval.ch = strdup(yytext); return(enot); }
"<true/>"		{ yylval.ival = 1; return(INUMBER); }
"<false/>"		{ yylval.ival = 0; return(INUMBER); }

%%
