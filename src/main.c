#include "sudoku.h"

// Кол-во пустых (незаполненных) ячеек
uint8_t unsolved = SIZE*SIZE;

int main() {
    if ((BASE > 4) || (BASE < 2)) {
        fprintf(stderr, "Error: invalid value for 'BASE' macro\n");
        fprintf(stderr, "BASE = %d\n", BASE);
        exit(EINVAL);
    }
    uint8_t **Puzzle;
    Puzzle = createPuzzle();
    Cell **Cells = setupCells(Puzzle);
    printPuzzle(convertCellstoPuzzle(Cells));
    return 0;
}