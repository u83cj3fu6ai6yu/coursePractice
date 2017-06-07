%{
#include "Equ1.tab.h"

%}

%%

\n	{ return(0); /* EOF */ }

[ \t]+	{ /* do nothing */ }
[0-9]+	{ yylval.ival = atoi(yytext); return(INUMBER); }
[A-Z][a-z]? {//yylval.el.ele = strdup(yytext);
         	   if(yyleng == 2){
			char* tempC = strdup(yytext);
			int temp = (int) tempC[0];			
			temp = (temp-64)*100;
			temp = temp + (((int) tempC[1])-96);
			//printf("%d\n", temp);
			yylval.ival = temp;
		    }
		    if(yyleng == 1)
		    {
			char* tempC = strdup(yytext);
			int temp = (int) tempC[0];			
			temp = (temp-64)*100;
			//printf("%d\n", temp);
			yylval.ival = temp;
		    }
			 return(ELEMENT);
		}
.	{ return(yytext[0]); }
%%
