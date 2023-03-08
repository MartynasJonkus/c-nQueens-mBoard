//LSP - 2213732, e-mail - martynas.jonkus@mif.stud.vu.lt
//2nd ADS exercise, 14th variant
#include <stdio.h>
#include <stdlib.h>

#include "solveQueens.h"

int main() {
    Board *board = malloc(sizeof(Board));

    int n = get_positive_integer("Enter the number of queens (N): ");
    int m = get_positive_integer("Enter the size of the board (M): ");

    if (solveNQueens(n, m, board)) {
        printf("Valid placement:\n");
        printBoard(m, board);
    } else {
        printf("No valid placement found.\n");
    }

    freeBoard(m, board);

    return 0;
}