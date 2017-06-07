bison -d -o prob6B.tab.c prob6B.y
g++ -c -g -I.. prob6B.tab.c
flex -o prob6B.yy.c prob6B.l
g++ -c -g -I.. prob6B.yy.c
g++ -o prob6B prob6B.tab.o prob6B.yy.o -lfl -ly
