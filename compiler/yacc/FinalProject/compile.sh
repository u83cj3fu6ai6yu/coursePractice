bison -d -o FinalProject.tab.c FinalProject.y
gcc -c -g -I.. FinalProject.tab.c
flex -o FinalProject.yy.c FinalProject.l
gcc -c -g -I.. FinalProject.yy.c
gcc -o FinalProject FinalProject.tab.o FinalProject.yy.o -lfl -ly
