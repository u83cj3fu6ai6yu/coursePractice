%{
#define DIGITS 258
#define LETTER 259
struct token {
    int val;
    char id;
} yylval;
%}
%x COMMENT
%%
"//"		{ BEGIN COMMENT; }
<COMMENT>.	;
<COMMENT>\n	{ BEGIN INITIAL; }
[0-9]+		{ ECHO; }
[_a-zA-Z]+	{ ECHO;	 }
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
