%{
int is_lower_alpha(char i) {
  return i >= 'a' && i <= 'z';
}

int is_upper_alpha(char i) {
  return i >= 'A' && i <= 'Z';
}

int is_alpha(char i) {
  return is_lower_alpha(i) || is_upper_alpha(i);
}

int is_num(char i) {
  return i >= '0' && i <= '9';
}

int one_of(char i, char* list) {
  for (int j = 0; list[j] != '\0'; j++) {
    if (i == list[j]) {
      return 1;
    }
  }
  return 0;
}

unsigned int charCount=0, wordCount=0, lineCount=0;
int is_valid_token(char* input) {
  if (input[0] == '\0') {
    return 0;
  }
  if (!(is_alpha(input[0]) || one_of(input[0], "_$"))) {
    return 0;
  }
  for (int i = 1; input[i] != '\0'; i++) {
    if (!(is_alpha(input[i]) || is_num(input[i]) || one_of(input[i], "_$"))) {
      return 0;    }
  }
  return 1;
}
%}
word    [^ ();\t\n]+
eol    \n
%%
{word}    { wordCount++; charCount += yyleng; if (is_valid_token(yytext) && strstr(yytext, "cpy")) { ECHO; fprintf(yyout, "\n"); } }
{eol}    { charCount++; lineCount++; }
.    charCount++;
%%
int main(int argc, char *argv[]) {
  yylex();
  return 0;
}
