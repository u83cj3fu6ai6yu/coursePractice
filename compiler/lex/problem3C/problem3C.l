nothex		^([0-9a-zA-Z])0([xX])([0-9a-fA-F]){4,6}$
hex1		^0([xX])([0-9a-fA-F]){4,6}$
hex2		0([xX])([0-9a-fA-F]){4,6}$
%%
\n		;
{nothex}	;
{hex1}	{ ECHO; printf("\n"); }
{hex2}	{ ECHO; printf("\n"); }
.		;
%%
int main(int argc, char *argv[]) {
	yylex();
	return(0);
}
