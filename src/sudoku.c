#include "sudoku.h"

// Создание динамического массива поля
uint8_t** createPuzzle(void) {
    uint8_t array[SIZE][SIZE] = {{0,1,9,  0,0,2,  0,0,0},
                                 {4,7,0,  6,9,0,  0,0,1},
                                 {0,0,0,  4,0,0,  0,9,0},

                                 {8,9,4,  5,0,7,  0,0,0},
                                 {0,0,0,  0,0,0,  0,0,0},
                                 {0,0,0,  2,0,1,  9,5,8},

                                 {0,5,0,  0,0,6,  0,0,0},
                                 {6,0,0,  0,2,8,  0,7,9},
                                 {0,0,0,  1,0,0,  8,6,0}};
    uint8_t** puzzle;
    puzzle = (uint8_t**) malloc(SIZE*sizeof(uint8_t*));
    for (uint8_t i = 0; i < SIZE; i++) {
        puzzle[i] = (uint8_t*) malloc(SIZE*sizeof(uint8_t));
        for (uint8_t j = 0; j < SIZE; j++)
            puzzle[i][j] = array[i][j];
    }
    return puzzle;
}

// Вывод поля на экран
void printPuzzle(uint8_t** puzzle) {
    printf(" --------------------------------\n");
    for (uint8_t i = 0; i < SIZE; i++) {
        printf(" | ");
        for (uint8_t j = 0; j < SIZE; j++) {
            printf(" %d ", puzzle[i][j]);
            if (((j+1) % BASE) == 0)
                printf("|");
        }
        if ((i+1) % BASE == 0)
            printf("\n --------------------------------");
        printf("\n");
    }
}