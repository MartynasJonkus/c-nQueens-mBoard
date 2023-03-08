//LSP - 2213732, e-mail - martynas.jonkus@mif.stud.vu.lt
//2nd ADS exercise, 14th variant
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "solveQueens.h"

void testSolveNQueensValid(int n, int m){
    Board* board = (Board*)malloc(sizeof(Board));
    assert(solveNQueens(n, m, board));
    freeBoard(m, board);
}

void testSolveNQueensInvalid(int n, int m){
    Board* board = (Board*)malloc(sizeof(Board));
    assert(!solveNQueens(n, m, board));
    freeBoard(m, board);
}

int main() {
    testSolveNQueensValid(3, 4);
    testSolveNQueensValid(4, 6);
    testSolveNQueensValid(12, 20);
    testSolveNQueensInvalid(4, 5);
    testSolveNQueensInvalid(10, 10);
    testSolveNQueensInvalid(15, 10);


    printf("All tests passed.\n");

    Board *board = malloc(sizeof(Board));

    int n = get_positive_integer("\"Enter the number of queens (N): \"\n");
    int m = get_positive_integer("\"Enter the size of the board (M): \"\n");

    printf("------------------------------------------\n");
    printf("%d queens on an %d-sized triangular board.\n", n, m);
    if (solveNQueens(n, m, board)) {
        printf("Valid placement:\n");
        printBoard(m, board);
    } else {
        printf("No valid placement found.\n");
    }

    freeBoard(m, board);

    return 0;
}