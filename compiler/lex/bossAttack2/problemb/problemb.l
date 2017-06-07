type1		[0-9]+([ ])("cup"|"cups"|tablespoon|tablespoons|teaspoon|teaspoons)
type2		[0-9]+([\/])[0-9]+([ ])(cup|cups|tablespoon|tablespoons|teaspoon|teaspoons)
type3		[0-9]+([ ])[0-9]+([\/])[0-9]+([ ])(cup|cups|tablespoon|tablespoons|teaspoon|teaspoons)
%x COMMENT
%%
{type3}		{ ECHO; printf("\n"); }
{type2}		{ ECHO; printf("\n"); }
{type1}		{ ECHO; printf("\n"); }
"Directions"				{ BEGIN COMMENT; }
<COMMENT>{type3}|{type2}|{type1}	{ printf("# "); ECHO; printf("\n"); }
<COMMENT>.|\n				;
.|\n		;
%%
int main(int argc, char *argv[]) {
  yylex();
  return 0;
}
