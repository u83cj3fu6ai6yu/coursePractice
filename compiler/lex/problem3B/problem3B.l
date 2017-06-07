noodles		([a-zA-Z0-9]+)([ \t]+)([a-zA-Z0-9]+)([ \t]+)(noodles)([ \t]+)([a-zA-Z0-9]+)$
%%
\n		;
{noodles}	{ ECHO; printf("\n"); }
.		;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
