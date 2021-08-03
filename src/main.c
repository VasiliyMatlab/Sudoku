// Подключаемые заголовочные файлы
#include "sudoku.h"

// Кол-во пустых (незаполненных) ячеек
uint8_t unsolved;
// Ячейки
Cell **cells;
// Блоки
Box **boxes;

// Главная функция
int main(int argc, char *argv[]) {
    if ((BASE > 4) || (BASE < 2)) {
        fprintf(stderr, "Error: invalid value for 'BASE' macro\n");
        fprintf(stderr, "BASE = %d\n", BASE);
        exit(EINVAL);
    }
    if (argc < 2) {
        fprintf(stderr, "Error: not enough input arguments\n");
        exit(EIO);
    }
    if (!strcmp(argv[1], "--help") || !strcmp(argv[1], "-h")) {
        printf(MANUAL);
        return 0;
    }
    else if (!strcmp(argv[1], "--version") || !strcmp(argv[1], "-v")) {
        printf("sudoku version %s\n", VERSION);
        return 0;
    }
    else {
        for (uint8_t count = 1; count < argc; count++) {
            printf("\n\n Solving for %s file\n", argv[count]);
            unsolved = SIZE*SIZE;
            uint8_t **Puzzle;
            Puzzle = createPuzzle(argv[count]);
            uint8_t mem = unsolved;
            initSudoku(Puzzle);
            // Пока все ячейки не заполнены
            while (unsolved > 0) {
                checkPuzzle();
                // Если кол-во оставшихся незаполненных ячеек не изменилось
                if (unsolved == mem) {
                    printf(" Unable to solve the sudoku\n");
                    printf(" The last calculated field:\n");
                    break;
                }
                else
                    mem = unsolved;
            }
            // Если все ячейки заполнены
            if (!unsolved)
                printf(" Success!\n");
            Puzzle = convertCellstoPuzzle();
            printPuzzle(Puzzle);
            clearSudoku();
        }
    }
    return 0;
}