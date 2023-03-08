test.exe: test.c solveQueens.h solveQueens.o
	gcc -std=c99 -o test.exe test.c solveQueens.o

solveQueens.o: solveQueens.c solveQueens.h
	gcc -c -std=c99 solveQueens.c