#include "../include/sudoku.h"

int** createPuzzle(void) {
    int array[9][9] = {{0,1,9,  0,0,2,  0,0,0},
                       {4,7,0,  6,9,0,  0,0,1},
                       {0,0,0,  4,0,0,  0,9,0},

                       {8,9,4,  5,0,7,  0,0,0},
                       {0,0,0,  0,0,0,  0,0,0},
                       {0,0,0,  2,0,1,  9,5,8},

                       {0,5,0,  0,0,6,  0,0,0},
                       {6,0,0,  0,2,8,  0,7,9},
                       {0,0,0,  1,0,0,  8,6,0}};
    int **puzzle;
    puzzle = (int**) malloc(9*sizeof(int*));
    for (int i = 0; i < SIZE_ROWS; i++) {
        puzzle[i] = (int*) malloc(9*sizeof(int));
        for (int j = 0; j < SIZE_COLUMNS; j++)
            puzzle[i][j] = array[i][j];
    }
    return puzzle;
}

void printPuzzle(int** puzzle) {
    printf(" --------------------------------\n");
    for (int i = 0; i < SIZE_ROWS; i++) {
        printf(" | ");
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            printf(" %d ", puzzle[i][j]);
            if (((j+1) % 3) == 0)
                printf("|");
        }
        if ((i+1) % 3 == 0)
            printf("\n --------------------------------");
        printf("\n");
    }
}

Square*** setUpPuzzle(int** puzzle) {
    Square*** sudoku;
    // malloc space for each row
    sudoku = (Square***) malloc(9*sizeof(Square**));
    // loop through rows
    for (int i = 0; i < SIZE_ROWS; i++) {
        // malloc space for each column
        sudoku[i] = (Square**) malloc(9*sizeof(Square*));
        // loop through columns
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            // WTF?
            sudoku[i][j] = (Square*) malloc(9*sizeof(Square));
            // assign number to sudoku apt
            sudoku[i][j]->number = puzzle[i][j];
            // assign row and column numbers to each square
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            // if number isn't zero, the square isn't empty
            if (sudoku[i][j]->number != 0)
                sudoku[i][j]->code = POSSIBLE;
            // else the square is empty
            else
                sudoku[i][j]->code = 0x0;
        }
    }
    return sudoku;
}