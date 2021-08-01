#include "sudoku.h"

extern uint8_t unsolved;
extern Cell **cells;
extern Box **boxes;

// Создание массива поля
uint8_t **createPuzzle(void) {
    uint8_t rows, columns;
    uint8_t **array = readArray(FILENAME, &rows, &columns);
    if (rows != columns) {
        fprintf(stderr, \
            "Error: 'rows' variable not equal to 'columns' variable\n");
        fprintf(stderr, "rows = %d, columns = %d\n", rows, columns);
        exit(EINVAL);
    }
    if ((rows != SIZE) || (columns != SIZE)) {
        fprintf(stderr, \
            "Error: 'rows' or 'columns' variable not equal to 'SIZE' macro\n");
        fprintf(stderr, "rows = %d, columns = %d\n", rows, columns);
        fprintf(stderr, "SIZE = %d\n", SIZE);
        exit(EINVAL);
    }
    return array;
}

// Вывод поля на экран
void printPuzzle(uint8_t **puzzle) {
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

// Инициализация массива структур поля
void initSudoku(uint8_t **puzzle) {
    setupCells(puzzle);
    setupBoxes();
    // Обновление данных в ячейках за счет ячеек
    // Цикл по строкам
    for (uint8_t i = 0; i < SIZE; i++) {
        // Цикл по столбцам
        for (uint8_t j = 0; j < SIZE; j++) {
            // Если в ячейке не нуль
            if (cells[i][j].number) {
                // Изменение ячейки
                cells[i][j].code = (~0) >> (CODE_BITS - SIZE);
                cells[i][j].possible = 0;
                unsolved--;
                // Изменение блока
                uint8_t x = i / BASE;   // строка блока
                uint8_t y = j / BASE;   // столбец блока
                boxes[x][y].code |= 1 << (cells[i][j].number-1);
                boxes[x][y].possible--;
                // Обновление строки, столбца, ячеек блока
                updateRow(i, cells[i][j].number);
                updateColumn(j, cells[i][j].number);
                updateBox(x, y, cells[i][j].number);
            }
        }
    }
}

// Инициализация ячеек
void setupCells(uint8_t **puzzle) {
    cells = (Cell **) malloc(SIZE*sizeof(Cell *));
    // Занесение данных в ячейки
    // Цикл по строкам
    for (uint8_t i = 0; i < SIZE; i++) {
        cells[i] = (Cell *) malloc(SIZE*sizeof(Cell));
        // Цикл по столбцам
        for (uint8_t j = 0; j < SIZE; j++) {
            cells[i][j].row = i;
            cells[i][j].column = j;
            cells[i][j].number = puzzle[i][j];
            cells[i][j].code = 0;
            cells[i][j].possible = SIZE;
        }
    }
}

// Инициализация блоков
void setupBoxes(void) {
    boxes = (Box **) malloc(BASE*sizeof(Box *));
    // Занесение данных в блоки
    // Цикл по строкам
    for (uint8_t x = 0; x < BASE; x++) {
        boxes[x] = (Box *) malloc(BASE*sizeof(Box));
        // Цикл по столбцам
        for (uint8_t y = 0; y < BASE; y++) {
            boxes[x][y].box_row = x;
            boxes[x][y].box_column = y;
            boxes[x][y].code = 0;
            boxes[x][y].possible = SIZE;
        }
    }
}

// Проверка поля на доступность записи значения
void checkPuzzle(void) {
    // Цикл по строкам
    for (uint8_t i = 0; i < SIZE; i++) {
        // Цикл по столбцам
        for (uint8_t j = 0; j < SIZE; j++) {
            // Если в ячейке не записано число
            if (!cells[i][j].number) {
                // Проверяем, сколько
                // существует доступных значений
                uint8_t avaliable = 0;
                // Цикл по доступным значениям
                for (uint8_t k = 1; k <= SIZE; k++) {
                    // Если значение доступно
                    if (!(cells[i][j].code & (1 << (k-1)))) {
                        // Если до этого не было найдено доступных значений,
                        // то данное будет первым
                        if (!avaliable)
                            avaliable = k;
                        // Иначе доступных значений несколько,
                        // поэтому проверяем следующую ячейку
                        else {
                            avaliable = 0;
                            break;
                        }
                    }
                }
                // Если доступное значение единственное
                if (avaliable) {
                    // Изменение ячейки
                    cells[i][j].number = avaliable;
                    cells[i][j].code = (~0) >> (CODE_BITS - SIZE);
                    cells[i][j].possible = 0;
                    unsolved--;
                    // Изменение блока
                    uint8_t x = i / BASE;   // строка блока
                    uint8_t y = j / BASE;   // столбец блока
                    boxes[x][y].code |= 1 << (cells[i][j].number-1);
                    boxes[x][y].possible--;
                    // Обновление строки, столбца, ячеек блока
                    updateRow(i, cells[i][j].number);
                    updateColumn(j, cells[i][j].number);
                    updateBox(x, y, cells[i][j].number);
                }
            }
        }
    }
}

// Обновление строки (запись обновленных данных в другие ячейки)
void updateRow(uint8_t row, uint8_t num) {
    // Цикл по столбцам
    for (uint8_t j = 0; j < SIZE; j++) {
        if (!cells[row][j].number) {
            cells[row][j].code |= 1 << (num-1);
            cells[row][j].possible--;
        }
    }
}

// Обновление столбца (запись обновленных данных в другие ячейки)
void updateColumn(uint8_t column, uint8_t num) {
    // Цикл по строкам
    for (uint8_t i = 0; i < SIZE; i++) {
        if (!cells[i][column].number) {
            cells[i][column].code |= 1 << (num-1);
            cells[i][column].possible--;
        }
    }
}

// Обновление блока (запись обновленных данных в другие ячейки)
void updateBox(uint8_t x, uint8_t y, uint8_t num) {
    // Цикл по строкам блока
    for (uint8_t i = 0; i < BASE; i++) {
        // Цикл по столбцам блока
        for (uint8_t j = 0; j < BASE; j++) {
            // Если ячейка пустая
            if (!cells[BASE*x + i][BASE*y + j].number) {
                cells[BASE*x + i][BASE*y + j].code |= 1 << (num-1);
                cells[BASE*x + i][BASE*y + j].possible--;
            }
        }
    }
}

// Конвертирование массива структур ячеек в массив поля
uint8_t **convertCellstoPuzzle(void) {
    uint8_t **puzzle = (uint8_t **) malloc(SIZE*sizeof(uint8_t *));
    // Цикл по строкам
    for (uint8_t i = 0; i < SIZE; i++) {
        puzzle[i] = (uint8_t *) malloc(SIZE*sizeof(uint8_t));
        // Цикл по столбцам
        for (uint8_t j = 0; j < SIZE; j++)
            puzzle[i][j] = cells[i][j].number;
    }
    return puzzle;
}