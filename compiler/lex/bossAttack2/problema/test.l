%{
#include <vector>
char* lasttoken = "w";
int lastlen = 1;
int indent = 0;
int i = 0;
int key = 0;

int is_different_token(int len, char* input) {
	if (lastlen != len) {
		return 1;
	}
	else {
		while( (*(input)) != '\0' ) {
			if ( (*(input)) != (*(lasttoken)) ) {
				return 1;
			}
			input++;
			lasttoken++;
		}
		return 0;
	}
}
void change(int len, char* input) {
	lasttoken = input;
	lastlen = len;
}
void first(int len, char* input) {
	if (key == 0) {
		lasttoken = input;
		lastlen = len;
	}
	key = key + 1;
}
%}
tag		<([a-zA-Z_]+)>
%%
{tag}		{ first(yyleng, yytext);  if (is_different_token(yyleng, yytext)) indent = indent + 1; for (i=0; i<indent; i++) printf("  "); ECHO; printf("\n"); change(yyleng, yytext); 	}
.|\n		;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
