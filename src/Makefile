BIN = ../bin
BUILD = ../build
PROJECT = sudoku
CC = gcc
CFLAGS = -c -Wall -Werror -std=gnu17 -O3
LDFLAGS = -g -Wall -Werror -std=gnu17 -O3

all: start building
	@ echo Building is complete

start:
	@ echo Start building
	mkdir -pv ../build
	mkdir -pv ../bin

building: $(BUILD)/main.o $(BUILD)/sudoku.o $(BUILD)/internal.o
	$(CC) $(LDFLAGS) $(BUILD)/main.o $(BUILD)/sudoku.o $(BUILD)/internal.o -o $(BIN)/$(PROJECT).elf

$(BUILD)/main.o: main.c sudoku.h internal.h
	$(CC) $(CFLAGS) main.c -o $(BUILD)/main.o

$(BUILD)/sudoku.o: sudoku.c sudoku.h internal.h
	$(CC) $(CFLAGS) sudoku.c -o $(BUILD)/sudoku.o

$(BUILD)/internal.o: internal.c internal.h
	$(CC) $(CFLAGS) internal.c -o $(BUILD)/internal.o

archiving:
	cd $(BIN)/ && tar -zcvf Binaries.tar.gz $(PROJECT)

clean:
	rm -rv $(BUILD)
	rm -rv $(BIN)
