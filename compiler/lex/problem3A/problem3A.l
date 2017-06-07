cpy		([a-zA-Z_\$]*)(cpy)([a-zA-Z0-9_\$]*)
%%
\n		;
{cpy}		{ ECHO; printf("\n"); }
.		;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
