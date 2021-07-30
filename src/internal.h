#ifndef INTERNAL_H
#define INTETNAL_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 128
#define FILENAME "../bin/data.dan"

uint8_t** readArray(char *, uint8_t *, uint8_t *);

#endif