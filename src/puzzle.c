#include "puzzle.h"

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
    for (int i = 0; i < 9; i++) {
        puzzle[i] = (int*) malloc(9*sizeof(int));
        for (int j = 0; j < 9; j++)
            puzzle[i][j] = array[i][j];
    }
    return puzzle;
}

void printPuzzle(int** puzzle) {
    printf(" --------------------------------\n");
    for (int i = 0; i < 9; i++) {
        printf(" | ");
        for (int j = 0; j < 9; j++) {
            printf(" %d ", puzzle[i][j]);
            if (((j+1) % 3) == 0)
                printf("|");
        }
        if ((i+1) % 3 == 0)
            printf("\n --------------------------------");
        printf("\n");
    }
}