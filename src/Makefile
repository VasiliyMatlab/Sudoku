CC = gcc
CFLAGS = -c -Wall
BIN = ../bin
BUILD = ../build

all: start building
	@ echo Building is complete

start:
	@ echo Start building

building: $(BUILD)/main.o $(BUILD)/sudoku.o
	$(CC) $(BUILD)/main.o $(BUILD)/sudoku.o -o $(BIN)/Sudoku

$(BUILD)/main.o: main.c sudoku.h
	$(CC) $(CFLAGS) main.c -o $(BUILD)/main.o

$(BUILD)/sudoku.o: sudoku.c sudoku.h
	$(CC) $(CFLAGS) sudoku.c -o $(BUILD)/sudoku.o