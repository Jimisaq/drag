#include <stdio.h>
#include <stdbool.h>

#define SIZE 9

bool isValid(int board[SIZE][SIZE], int row, int col, int num);
bool solveSudoku(int board[SIZE][SIZE]);
bool findEmpty(int board[SIZE][SIZE], int* row, int* col);
void printBoard(int board[SIZE][SIZE]);

int main() {
    int board[SIZE][SIZE] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

printf("Original Sudoku:\n");
    printBoard(board);

    if (solveSudoku(board)){
        printf("\nSolved Sudoku:\n");
        printBoard(board);
    } else{
        printf("\nNo solution exists.\n");
    }

    return 0;
}

bool isValid(int board[SIZE][SIZE], int row, int col, int num){
    // Check row and column
        for (int i = 0; i < SIZE; i++){
            if (board[row][i] == num || board[i][col] == num){
                return false;
            }
        }

    // Check 3x3 sub-grid
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++) {
                if (board[i + startRow][j + startCol] == num){
                    return false;
                }
            }
        }
    return true;
}

bool solveSudoku(int board[SIZE][SIZE]){
    int row, col;

    if (!findEmpty(board, &row, &col)){
        return true; // Board is filled
    }

    for (int num = 1; num <= SIZE; num++){
        if (isValid(board, row, col, num)){
            board[row][col] = num;

            if (solveSudoku(board)){
                return true;
            }

            board[row][col] = 0; // Backtrack
        }
    }

    return false;
}
bool findEmpty(int board[SIZE][SIZE], int* row, int* col){
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++){
            if (board[i][j] == 0){
                *row = i;
                *col = j;
                return true;
            }
        }
    }

    return false;
}

void printBoard(int board[SIZE][SIZE]){
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            printf("%d ", board[i][j]);
            if ((j + 1) % 3 == 0 && j < 8){
                printf(" ");
            }
        }
        printf("\n");
        if ((i + 1) % 3 == 0 && i < 8){
            printf("\n");
        }
    }
}
