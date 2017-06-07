bison -d -o prob6A.tab.c prob6A.y
gcc -c -g -I.. prob6A.tab.c
flex -o prob6A.yy.c prob6A.l
gcc -c -g -I.. prob6A.yy.c
gcc -o prob6A prob6A.tab.o prob6A.yy.o -lfl -ly
