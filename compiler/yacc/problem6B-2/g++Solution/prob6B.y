%{

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>

int yylex(void);
void yyerror(const char *message);

using namespace std;
void print(void);
void parser(char *text);
void parser2(char *text, char *rtext, int last);
map<char, int> m;
map<char, int>::iterator iter;
extern int key;

%}
%union {
	char* str;
}


%type  <str> expr
%token  <str> words
%left '+'

%%

line	: expr '-' '>' expr		{ print(); }
	;

expr	: expr '+' expr			{ ; }
	| words				{ parser($1); }
	;

%%

void print(void) {
	for(iter = m.begin(); iter != m.end(); iter++) {
		if(iter->second == 0)
			continue;
		else
			printf("%c %d\n", iter->first, iter->second);
	}
}

void parser(char *text) {
	int i = 0;
	int first = 1;
	char *ltext;
	while(*text != '\0') {
		if(*text == 40) {
			ltext = text;
			while( *text != 41 )
				text++;
			parser2(ltext+1, text, *(text+1)-48);
			text ++;
		}
		else if(*text >= 49 && *text <= 57) {
			if(i == 0) {
				first = *text-48;
				text++;
				i++;
				continue;
			}
			iter = m.find(*(text-1));
			iter->second += first * key * (*text-49);
		}
		else {
			iter = m.find(*text);
			if(iter != m.end())
				iter->second += first * key;
			else
				m.insert(pair<char, int>(*text, first * key));
		}
		text++;
		i++;
	}
}

void parser2(char *text, char *rtext, int last) {
	if(*text >= 49 && *text <= 57) {
		printf("Invalid format\n");
		exit(0);
	}
	while(*text != *rtext) {
		if(*text >= 49 && *text <= 57) {
			iter = m.find(*(text-1));
			iter->second += last * key * (*text-49);
		}
		else {
			iter = m.find(*text);
			if(iter != m.end())
				iter->second += last * key;
			else
				m.insert(pair<char, int>(*text, last * key));
		}
		text++;
	}
}

void yyerror (const char *message) {
	fprintf (stderr, "%s\n", message);
}

int main(int argc, char *argv[]) {
        yyparse();
        return 0;
}
