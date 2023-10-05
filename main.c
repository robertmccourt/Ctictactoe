#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool GameOver = false;
char player = 'x';
char computer = 'o';
int dimension;

bool checkWin(char **board, char symbol);
bool playerTurn(char **board);
bool computerTurn(char **board);
char **initBoard(int rows, int cols);
void printBoard(char **board, int rows, int cols);

int main() {
    printf("Welcome to tic-tac-toe mothafucka!\n");

    dimension = 3;
    int rows = 3;
    int cols = 3;

    char **board = initBoard(dimension, dimension);
    printBoard(board, rows, cols);

    while (!GameOver) {
        if (!playerTurn(board)) {
            printf("Player wins!");
            GameOver = true;
        } else if (!computerTurn(board)) {
            printf("Computer Wins!");
            GameOver = true;
        }
    }

    return 0;
}

bool playerTurn(char **board) {

    return checkWin(board, player);
}
bool computerTurn(char **board) {
    return checkWin(board, computer);
}

bool checkWin(char **board, char symbol) {
    // Check rows
    int row_count = 0;
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            if (board[i][j] == symbol) {
                row_count++;
            }
        }
    }

    //Check columns
    int col_count = 0;
    for (int j = 0; j < dimension; j++) {
        for (int i = 0; i < dimension; i++) {
            if (board[i][j] == symbol) {
                col_count++;
            }
        }
    }

    //Check diagonal
    int diag_count = 0;
    for (int i = 0; i < dimension; i++) {
        if (board[i][i] == symbol) {
            diag_count++;
        }
    }

    //Check anti-diagonal
    int anti_diag = 0;
    for (int i = 0; i < dimension; i++) {
        if (board[i][dimension-1-i] == symbol) {
            anti_diag++;
        }
    }

    return (anti_diag == dimension || diag_count == dimension ||
            row_count == dimension || col_count == dimension) ? true : false;
}

void printBoard(char **board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

char **initBoard(int rows, int cols) {
    char **board = (char **) malloc(rows * sizeof(char *));

    if (board == NULL) {
        printf("Error initializing board");
    }

    for (int i = 0; i < rows; i++) {
        board[i] = (char *) malloc(cols * sizeof(char));
        for (int j = 0; j < cols; j++) {
            board[i][j] = '-';
        }
    }

    return board;
}


