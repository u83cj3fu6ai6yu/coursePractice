bison -d -o bit.tab.c bit.y
gcc -c -g -I.. bit.tab.c
flex -o bit.yy.c bit.l
gcc -c -g -I.. bit.yy.c
gcc -o bit bit.tab.o bit.yy.o -lfl -ly
