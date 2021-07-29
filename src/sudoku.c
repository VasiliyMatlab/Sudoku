#include "../include/sudoku.h"

int UNSOLVED = 81;
int SIZE_ROWS = 9;
int SIZE_COLUMNS = 9;

int main() {
    int** puzzle;
    Sudoku* sudoku;
    int progress;
    puzzle = createPuzzle();
    sudoku = setUpPuzzle(puzzle);
    printPuzzle(sudoku->squares);
    while (UNSOLVED > 0) {
        progress = checkPuzzle(sudoku->squares, sudoku->boxes);
        if (progress == 0) {
            printf("\nFailed to solve the puzzle!\n");
            break;
        }
    }
    printf("\n\n");
    printPuzzle(sudoku->squares);
    return 0;
}