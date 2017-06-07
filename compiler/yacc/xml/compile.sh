bison -d -o xml.tab.c xml.y
gcc -c -g -I.. xml.tab.c
flex -o xml.yy.c xml.l
gcc -c -g -I.. xml.yy.c
gcc -o xml xml.tab.o xml.yy.o -lfl -ly
