#ifndef INTERNAL_H
#define INTETNAL_H

// Подключаемые заголовочные файлы
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Макросы
#define BUFFER_SIZE 128
#define FILENAME "data.dan"

// Прототипы функций
uint8_t** readArray(char *, uint8_t *, uint8_t *);

#endif