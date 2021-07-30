#include "sudoku.h"

extern uint8_t unsolved;

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

// Инициализация ячеек
Cell **setupCells(uint8_t **puzzle) {
    Cell **cells = (Cell **) malloc(SIZE*sizeof(Cell *));
    // Цикл по строкам
    for (uint8_t i = 0; i < SIZE; i++) {
        cells[i] = (Cell *) malloc(SIZE*sizeof(Cell));
        // Цикл по столбцам
        for (uint8_t j = 0; j < SIZE; j++) {
            cells[i][j].row = i;
            cells[i][j].column = j;
            cells[i][j].number = puzzle[i][j];
            // Если в ячейке не нуль
            if (puzzle[i][j]) {
                cells[i][j].code = (~0) >> (CODE_BITS - SIZE);
                cells[i][j].possible = 0;
                unsolved--;
            }
            // Если в ячейке нуль
            else {
                cells[i][j].code = 0;
                cells[i][j].possible = SIZE;
            }
        }
    }
    return cells;
}

// Инициализация блоков
Box **setupBoxes(Cell ***cells) {
    return NULL;
}

// Проверка поля на доступность записи значения
void checkPuzzle(Box ***boxes, Cell ***cells) {

}

// Обновление строки (запись обновленных данных в другие ячейки)
void updateRow(Cell ***cells, uint8_t row, uint8_t num) {
    for (uint8_t j = 0; j < SIZE; j++) {
        if (cells[row][j]->number)
            continue;
        else {
            cells[row][j]->code |= 1 << (num-1);
            cells[row][j]->possible--;
        }
    }
}

// Обновление столбца (запись обновленных данных в другие ячейки)
void updateColumn(Cell ***cells, uint8_t column, uint8_t num) {
    for (uint8_t i = 0; i < SIZE; i++) {
        if (cells[i][column]->number)
            continue;
        else {
            cells[i][column]->code |= 1 << (num-1);
            cells[i][column]->possible--;
        }
    }
}

// Обновление блока (запись обновленных данных в другие ячейки)
void updateBox(Cell ***cells, uint8_t row, uint8_t column) {

}

// Конвертирование массива структур ячеек в массив поля
uint8_t **convertCellstoPuzzle(Cell **cells) {
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