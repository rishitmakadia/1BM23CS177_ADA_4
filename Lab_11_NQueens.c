#include <stdio.h>
#include <stdbool.h>

#define N 4

// Function to print the board configuration
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 1) {
                printf("Q ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if it's safe to place a queen at board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    // Check this row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on left side
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

// Function to solve the N-Queens problem using backtracking
void solveNQueen(int board[N][N], int col) {
    if (col == N) { 
        printSolution(board); // If all queens are placed, print the solution
        return; 
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; // Place the queen
            solveNQueen(board, col + 1); // Recur to place the next queen
            board[i][col] = 0; // Backtrack
        }
    }
}

// Function to initiate the N-Queens solver
void NQueens() {
    int board[N][N] = {0}; // Initialize the board with 0 (no queens)
    solveNQueen(board, 0);  // Start solving from the first column
}

int main() {
    NQueens(); // Call the function to solve N-Queens
    return 0;
}
