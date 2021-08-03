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
#define VERSION "1.0"

// Прототипы функций
uint8_t** readArray(char *, uint8_t *, uint8_t *);

#define MANUAL \
"\n\e[1mNAME\e[0m\n\
\tsudoku - solve the sudoku puzzle\n\
\n\
\e[1mSYNOPSIS\e[0m\n\
\t\e[1msudoku\e[0m [\e[4mOPTION\e[0m]\n\
\t\e[1msudoku\e[0m \e[4mSOURSE\e[0m...\n\
\n\
\e[1mDESCRIPTION\e[0m\n\
\tSolve the sudoku puzzle in the SOURSE.\n\
\n \
\tMandatory arguments to long options are mandatory for short options too.\n\
\n\
\t\e[1m-h, --help\e[0m\n\
\t\tprint usage\n\
\n\
\t\e[1m-v, --version\e[0m\n\
\t\tprint version\n\
\n\
\e[1mEXAMPLE\e[0m\n\
\tsudoku file1.dan file2.txt\n\
\n\
\e[1mAUTHOR\e[0m\n\
\tWritten by Vasily Voronin.\n\
\n\
\e[1mCOPYRIGHT\e[0m\n\
\tCopyright (C) 2017 Free Software Foundation, Inc. \
GCC version 7.5.0 or later.\n\
\tThis is free software: you are free to change and redistribute it.\n\
\e[1mSEE ALSO\e[0m\n\
\tFull documentation at : <https://github.com/VasiliyMatlab/Sudoku>\n\n"

#endif