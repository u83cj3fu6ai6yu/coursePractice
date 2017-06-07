#compile bison
bison -d -o ex1.tab.c ex1.y
gcc -c -g -I.. ex1.tab.c
#compile flex
flex -o ex1.yy.c ex1.l
gcc -c -g -I.. ex1.yy.c
#compile and link bison and flex
gcc -o ex1 ex1.tab.o ex1.yy.o -ll
