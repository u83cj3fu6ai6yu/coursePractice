%{
#include "test.tab.h"
%}
%%

[ \t\n]+			{}
"print-num"		{ yylval.ch = strdup(yytext); return(printnum); }
"print-bool"		{ yylval.ch = strdup(yytext); return(printbool); }
[+-]?[0-9]+		{ yylval.ival = atoi(yytext); return(number); }
"#t"			{ yylval.ival = 1; return(bool_val); }
"#f"			{ yylval.ival = 0; return(bool_val); }
.			{ return(yytext[0]); }
