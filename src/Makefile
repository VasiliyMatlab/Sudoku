CC = gcc
CFLAGS = -c -Wall
BIN = ../bin
BUILD = ../build

all: start building
	@ echo Building is complete

start:
	@ echo Start building

building: $(BUILD)/sudoku.o $(BUILD)/puzzle.o
	$(CC) $(BUILD)/sudoku.o $(BUILD)/puzzle.o -o $(BIN)/Sudoku

$(BUILD)/sudoku.o: sudoku.c puzzle.h
	$(CC) $(CFLAGS) sudoku.c -o $(BUILD)/sudoku.o

$(BUILD)/puzzle.o: puzzle.c puzzle.h
	$(CC) $(CFLAGS) puzzle.c -o $(BUILD)/puzzle.o
