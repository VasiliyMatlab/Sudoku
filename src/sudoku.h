#ifndef PUZZLE_H
#define PUZZLE_H

// Подключаемые заголовочные файлы
#include "internal.h"

// Макросы
#define BASE 3
#define SIZE BASE*BASE
#define CODE_BITS 16

// Блок
typedef struct Box {
    uint8_t box_row;            // строка блока
    uint8_t box_column;         // столбец блока
    uint16_t code;              // битовое представление возможных значений
    /* XXXX XXX1 1011 0110
       XXXX XXX9 8765 4321
       0 - значение доступно
       1 - значение недоступно
       X - значение не анализируется (по умолчанию 0) */
    uint8_t possible;           // кол-во возможных значений
} Box;

// Ячейка
typedef struct Cell {
    uint8_t row;                // строка
    uint8_t column;             // столбец
    uint8_t number;             // цифра, записанная в ячейке
    uint16_t code;              // битовое представление возможных значений
    uint8_t possible;           // кол-во возможных значений
} Cell;

// Прототипы функций
uint8_t **createPuzzle(char *);
uint8_t **convertCellstoPuzzle(void);
void printPuzzle(uint8_t **);
void initSudoku(uint8_t **);
void setupCells(uint8_t **);
void setupBoxes(void);
void updateRow(uint8_t, uint8_t);
void updateColumn(uint8_t, uint8_t);
void updateBox(uint8_t, uint8_t, uint8_t);
void checkPuzzle(void);
_Bool checkRow(uint8_t, uint8_t, uint8_t);
_Bool checkColumn(uint8_t, uint8_t, uint8_t);
_Bool checkBox(uint8_t, uint8_t, uint8_t);
void changing(uint8_t, uint8_t, uint8_t);
void clearSudoku();

#endif