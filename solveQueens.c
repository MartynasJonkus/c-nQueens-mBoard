//LSP - 2213732, e-mail - martynas.jonkus@mif.stud.vu.lt
//2nd ADS exercise, 14th variant
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "solveQueens.h"

bool solveNQueens(int n, int m, Board* board) {
    if (board == NULL){
        printf("Allocating memory for the board failed.\n");
        return false;
    }

    board->col = (bool *)malloc(m * sizeof(bool));
    board->diagonal = (bool *)malloc(m * sizeof(bool));
    board->state = (char **)malloc(m * sizeof(char *));
    if (board->col == NULL || board->diagonal == NULL || board->state == NULL){
        printf("Allocating memory for board->col or board->diagonal, board->state failed.\n");
        return false;
    }
    for (int i = 0; i < m; ++i) {
        board->state[i] = (char *)malloc(m * sizeof(char));
        if(board->state[i] == NULL){
            printf("Allocating memory for board->state[i] failed.\n");
            return false;
        }
    }

    if (n > m){
        printf("The number of queens exceeds the number of rows.\n");
        return false;
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            board->state[i][j] = 'o';
        }
        board->col[i] = false;
        board->diagonal[i] = false;
    }

    if (backtrack(0, n, m, board))
        return true;

    return false;
}

bool backtrack(int row, int n, int m, Board* board) {
    if (row == n)
        return true;

    for (int c = 0; c < (m - row); ++c) {
        if (!board->col[c] && !board->diagonal[row + c]) {
            board->state[row][c] = 'Q';
            board->col[c] = true;
            board->diagonal[row + c] = true;

            if (backtrack(row + 1, n, m, board))
                return true;

            board->state[row][c] = 'o';
            board->col[c] = false;
            board->diagonal[row + c] = false;
        }
    }
    return false;
}

int get_positive_integer(char msg[]) {
    int num = -1;
    int result;
    char extra;

    do {
        printf("%s", msg);
        result = scanf("%d%c", &num, &extra);
        if (result != 2 || extra != '\n') {
            printf("Invalid input. Please enter a non-negative integer.\n");
            while (getchar() != '\n');
        }else if(num < 0)
            printf("Invalid input. Please enter a non-negative integer.\n");
    } while (result != 2 || extra != '\n' || num < 0);

    return num;
}

void printBoard(int m, Board* board){
    for (int i = (m - 1); i >= 0; --i) {
        for (int j = 0; j < i; j++)
            printf("  ");

        for (int j = 0; j < (m - i); j++)
            printf("%c   ", board->state[i][j]);

        printf("\n");
    }
}

void freeBoard(int m, Board* board){
    free(board->col);

    free(board->diagonal);

    for (int i = 0; i < m; ++i) {
        free(board->state[i]);
    }
    free(board->state);

    free(board);
}
