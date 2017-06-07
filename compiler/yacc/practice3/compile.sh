bison -d -o calc.tab.c calc.y
gcc -c -g -I.. calc.tab.c
flex -o calc.yy.c calc.l
gcc -c -g -I.. calc.yy.c
gcc -o calc calc.tab.o calc.yy.o -lfl -ly
