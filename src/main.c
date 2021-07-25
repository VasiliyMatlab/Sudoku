#include "sudoku.h"

// Реализовать считывание поля из файла

int main() {
    uint8_t** Puzzle;
    Puzzle = createPuzzle();
    printPuzzle(Puzzle);
    return 0;
}