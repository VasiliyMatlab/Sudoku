CC = gcc
CFLAGS = -c -Wall
BIN = ../bin
BUILD = ../build
PROJECT = sudoku

all: start building
	@ echo Building is complete

start:
	@ echo Start building
	../scripts/helper.sh

building: $(BUILD)/main.o $(BUILD)/sudoku.o $(BUILD)/internal.o
	$(CC) -g $(BUILD)/main.o $(BUILD)/sudoku.o $(BUILD)/internal.o -o $(BIN)/$(PROJECT)

$(BUILD)/main.o: main.c sudoku.h internal.h
	$(CC) $(CFLAGS) main.c -o $(BUILD)/main.o

$(BUILD)/sudoku.o: sudoku.c sudoku.h internal.h
	$(CC) $(CFLAGS) sudoku.c -o $(BUILD)/sudoku.o

$(BUILD)/internal.o: internal.c internal.h
	$(CC) $(CFLAGS) internal.c -o $(BUILD)/internal.o

clean:
	rm $(BUILD)/*
	rm $(BIN)/*
