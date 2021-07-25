CC = gcc
CFLAGS = -c -Wall
INCLUDE = ./include
BIN = ./bin
BUILD = ./build
SRC = ./src

all: start building
	@ echo Building is complete

start:
	@ echo Start building

building: $(BUILD)/sudoku.o $(BUILD)/puzzle.o $(BUILD)/square.o
	$(CC) $(BUILD)/sudoku.o $(BUILD)/puzzle.o $(BUILD)/square.o -o $(BIN)/Sudoku

$(BUILD)/sudoku.o: $(SRC)/sudoku.c $(INCLUDE)/sudoku.h
	$(CC) $(CFLAGS) $(SRC)/sudoku.c -o $(BUILD)/sudoku.o

$(BUILD)/puzzle.o: $(SRC)/puzzle.c $(INCLUDE)/sudoku.h
	$(CC) $(CFLAGS) $(SRC)/puzzle.c -o $(BUILD)/puzzle.o

$(BUILD)/square.o: $(SRC)/square.c $(INCLUDE)/sudoku.h
	$(CC) $(CFLAGS) $(SRC)/square.c -o $(BUILD)/square.o

clean:
	rm $(BUILD)/*.o
	rm $(BIN)/*