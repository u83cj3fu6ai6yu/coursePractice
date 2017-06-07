%{
char* lasttoken = "w";
int indent = 0;
int i = 0;
int key = 0;

int is_different_token(char* input) {
	int a = 0, b = 0;
	for(int j=0; *(input+j) != '\0'; j++) {
		a++;
	}
	for(int j=0; *(lasttoken+j) !='\0'; j++) {
		b++;
	}
	if(a != b) {
		return 1;
	}
	else {
		for(int j=0; *(input+j) != '\0'; j++) {
			if( *(input+j) != *(lasttoken+j) ) {
				return 1;
			}
		}
		return 0;
	}
}
void change(char* input) {
	lasttoken = input;
}
%}
tag		<([a-zA-Z_]+)>
%%
{tag}		{ if (key == 0) lasttoken = yytext; key++; if (is_different_token(yytext)) indent++; for (i=0; i<indent; i++) printf("  "); ECHO; printf("\n"); change(yytext); }
.|\n		;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
