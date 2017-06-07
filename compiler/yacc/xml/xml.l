%{
#include "xml.tab.h"
%}


%%

[ \t\n]+		{}
.			{ return(yytext[0]); }

%%
