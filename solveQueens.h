#ifndef INC_2_ADS_QUEENS_SOLVEQUEENS_H
#define INC_2_ADS_QUEENS_SOLVEQUEENS_H

#include <stdbool.h>

typedef struct {
    bool* col;
    bool* diagonal;
    char** state;
} Board;

bool solveNQueens(int n, int m, Board* board);
bool backtrack(int row, int n, int m, Board* board);
int get_positive_integer(char msg[]);
void printBoard(int m, Board* board);
void freeBoard(int m, Board* board);

#endif
