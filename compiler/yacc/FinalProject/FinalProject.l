%{
#include "FinalProject.tab.h"
%}

separator		[\t\n\r ]
letter			[a-z]
digit			[0-9]
number			0|([1-9]{digit}*)|(-[1-9]{digit}*)
ID			{letter}({letter}|{digit}|'-')*
%%

{separator}+		{}
"print-num"		{ yylval.ch = strdup(yytext); return(printnum); }
"print-bool"		{ yylval.ch = strdup(yytext); return(printbool); }
"mod"			{ yylval.ch = strdup(yytext); return(mod); }
"and"			{ yylval.ch = strdup(yytext); return(and); }
"or"			{ yylval.ch = strdup(yytext); return(or); }
"not"			{ yylval.ch = strdup(yytext); return(not); }
"if"			{ yylval.ch = strdup(yytext); return(iff); }
"define"		{ yylval.ch = strdup(yytext); return(define); }
{number}		{ yylval.ival = atoi(yytext); return(number); }
{ID}			{ yylval.ch = strdup(yytext); return(id); }
"#t"			{ yylval.ival = 1; return(bool_val); }
"#f"			{ yylval.ival = 0; return(bool_val); }
.			{ return(yytext[0]); }
