#include "../include/sudoku.h"

int** createPuzzle() {
    int array[9][9] = {{0,1,9,  0,0,2,  0,0,0},
                       {4,7,0,  6,9,0,  0,0,1},
                       {0,0,0,  4,0,0,  0,9,0},

                       {8,9,4,  5,0,7,  0,0,0},
                       {0,0,0,  0,0,0,  0,0,0},
                       {0,0,0,  2,0,1,  9,5,8},

                       {0,5,0,  0,0,6,  0,0,0},
                       {6,0,0,  0,2,8,  0,7,9},
                       {0,0,0,  1,0,0,  8,6,0}};
    int **puzzle;
    puzzle = (int**) malloc(9*sizeof(int*));
    for (int i = 0; i < SIZE_ROWS; i++) {
        puzzle[i] = (int*) malloc(9*sizeof(int));
        for (int j = 0; j < SIZE_COLUMNS; j++)
            puzzle[i][j] = array[i][j];
    }
    return puzzle;
}

void printPuzzle(Square*** puzzle) {
    printf(" --------------------------------\n");
    for (int i = 0; i < SIZE_ROWS; i++) {
        printf(" | ");
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            printf(" %d ", (puzzle[i][j])->number);
            if (((j+1) % 3) == 0)
                printf("|");
        }
        if ((i+1) % 3 == 0)
            printf("\n --------------------------------");
        printf("\n");
    }
}

Sudoku* setUpPuzzle(int** puzzle) {
    Square*** sudoku;
    Box** boxes;
    int currentBox = 0;

    boxes = createBoxes();
    // malloc space for each row
    sudoku = (Square***) malloc(9*sizeof(Square**));
    // loop through rows
    for (int i = 0; i < SIZE_ROWS; i++) {
        // malloc space for each column
        sudoku[i] = (Square**) malloc(9*sizeof(Square*));
        // loop through columns
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            // WTF?
            sudoku[i][j] = (Square*) malloc(9*sizeof(Square));
            // assign number to sudoku apt
            sudoku[i][j]->number = puzzle[i][j];
            // assign row and column numbers to each square
            sudoku[i][j]->row = i;
            sudoku[i][j]->column = j;
            sudoku[i][j]->solvable = 9;
            boxes[currentBox]->squares[boxes[currentBox]->numbers] = sudoku[i][j];
            sudoku[i][j]->box = boxes[currentBox];
            boxes[currentBox]->numbers++;
            for (int x = 0; x < SIZE_ROWS; x++)
                sudoku[i][j]->possible[x] = 0;
            if (j == 2)
                currentBox++;
            if (j == 5)
                currentBox++;
        }
        currentBox -= 2;
        if (i == 2)
            currentBox += 3;
        if (i == 5)
            currentBox += 3;
    }

    // loop through rows
    for (int i = 0; i < SIZE_ROWS; i++) {
        // loop through columns
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->number != 0) {
                sudoku[i][j]->solvable = 0;
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
                UNSOLVED--;
            }
        }
    }

    return createSudoku(sudoku, boxes);
}

int updateSudoku(Square*** sudoku, int row, int column) {
    int number = sudoku[row][column]->number;

    for (int x = 0; x < SIZE_ROWS; x++) {
        if (sudoku[x][column]->possible[number-1] == 0)
            sudoku[x][column]->solvable--;
        sudoku[x][column]->possible[number-1] = 1;
    }

    for (int x = 0; x < SIZE_COLUMNS; x++) {
        if (sudoku[row][x]->possible[number-1] == 0)
            sudoku[row][x]->solvable--;
        sudoku[row][x]->possible[number-1] = 1;
    }

    return 1;
}

int checkPuzzle(Square*** sudoku, Box** boxes) {
    // loop through rows
    for (int i = 0; i < SIZE_ROWS; i++) {
        // loop through columns
        for (int j = 0; j < SIZE_COLUMNS; j++) {
            if (sudoku[i][j]->solvable == 1) {
                solveSquare(sudoku[i][j]);
                updateSudoku(sudoku, i, j);
                updateBoxes(sudoku, i, j);
            }
        }
    }
    boxSingles(sudoku, boxes);
    return 1;
}

Sudoku* createSudoku(Square*** squares, Box** boxes) {
    Sudoku *sudoku;

    sudoku = (Sudoku*) malloc(sizeof(Sudoku));
    sudoku->squares = squares;
    sudoku->boxes = boxes;

    return sudoku;
}