#include "sudoku.h"

int main() {
    if ((BASE > 4) || (BASE < 1)) {
        fprintf(stderr, "Error: invalid value for 'BASE' macro\n");
        fprintf(stderr, "BASE = %d\n", BASE);
        exit(EINVAL);
    }
    uint8_t **Puzzle;
    Puzzle = createPuzzle();
    printPuzzle(Puzzle);
    return 0;
}