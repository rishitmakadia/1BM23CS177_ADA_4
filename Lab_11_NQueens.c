#include<stdio.h>
#include<stdbool.h>
#define N 4
void printSolution(int board[N][N]){
    for(int i=0; i<N;i++){
        for(int j=0; j<N;j++)
            printf("%s", board[i][j]? "Q ":". ");
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N][N], int row,int col){
    for (int i=0; i<col;i++)
        if(board[row][i])
            return false;

    for(int i=row, j=col; i>=0 && j>=0; i--, j--)
        if(board[i][j])
            return false;

    for(int i=row, j=col; i<=N && j>=0; i++, j--)
        if(board[i][j])
            return false;

    return true;
}

void solveNQueen(int board[N][N], int col){
    if(col == N) { 
        printSolution(board); 
        return; 
    }

    for (int i=0; i<N; i++){
        if(isSafe(board, i, col)){
            board[i][col] = 1; 
            solveNQueen(board, col+1); 
            board[i][col] = 0; // Backtrack 
        }
    }
}


void NQueens(){
    int board[N][N] = {0}; // Initialize board with 0 (no queens)
    solveNQueen(board, 0); // Start solving the N-Queens problem from the first column
}

int main(){
    NQueens();
}