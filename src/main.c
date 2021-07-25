#include "sudoku.h"

int main() {
    int** Puzzle;
    Puzzle = createPuzzle();
    printPuzzle(Puzzle);
    return 0;
}