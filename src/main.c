#include "sudoku.h"

// Кол-во пустых (незаполненных) ячеек
uint8_t unsolved = SIZE*SIZE;

Cell **cells;
Box **boxes;

int main() {
    if ((BASE > 4) || (BASE < 2)) {
        fprintf(stderr, "Error: invalid value for 'BASE' macro\n");
        fprintf(stderr, "BASE = %d\n", BASE);
        exit(EINVAL);
    }
    uint8_t **Puzzle;
    Puzzle = createPuzzle();
    printPuzzle(Puzzle);
    uint8_t mem = unsolved;
    initSudoku(Puzzle);
    while (unsolved > 0) {
        checkPuzzle();
        if (unsolved == mem) {
            printf(" Unable to solve the sudoku\n");
            printf(" The last calculated field:\n");
            break;
        }
        else
            mem = unsolved;
    }
    if (!unsolved)
        printf(" Success!\n");
    Puzzle = convertCellstoPuzzle();
    printPuzzle(Puzzle);
    return 0;
}