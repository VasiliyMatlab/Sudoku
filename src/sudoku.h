#ifndef PUZZLE_H
#define PUZZLE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define BASE 3
#define SIZE BASE*BASE

// Блок
typedef struct Box {
    uint8_t box_row;        // строка блока
    uint8_t box_column;     // столбец блока
    struct Cell** cells;    // ячейки блока
    uint16_t code;          // битовое представление возможных значений
    /* XXXX XXX0 0000 0000
       XXXX XXX9 8765 4321
       0 - значение недоступно
       1 - значение доступно
       X - значение не анализируется (по умолчанию 0) */
    uint8_t possible;       // кол-во возможных значений
} Box;

// Ячейка
typedef struct Cell {
    uint8_t row;                // строка
    uint8_t column;             // столбец
    uint8_t number;             // цифра, записанная в ячейке
    uint16_t code;              // битовое представление возможных значений
    uint8_t possible;           // кол-во возможных значений
    struct Box *current_box;    // указатель на текущий блок
} Cell;

uint8_t** createPuzzle(void);
void printPuzzle(uint8_t**);

#endif