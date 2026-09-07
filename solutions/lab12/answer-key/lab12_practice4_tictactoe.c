/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice4_tictactoe.c
 * Description: Reads a 3x3 tic-tac-toe board and checks all rows,
 *              columns, and both diagonals for a winner.
 */

#include <stdio.h>
#include <string.h>

#define SIZE 3

void read_board(char board[][SIZE], int size);
char check_winner(const char board[][SIZE], int size);

/*
 * main: reads a SIZE x SIZE tic-tac-toe board and prints the winner,
 * or "No winner" if no player has three in a row.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char board[SIZE][SIZE];

    read_board(board, SIZE);

    char winner = check_winner(board, SIZE);
    if (winner == '.') {
        printf("No winner\n");
    } else {
        printf("Winner: %c\n", winner);
    }

    return 0;
}

/*
 * read_board: reads size rows of size characters ('X', 'O', or '.')
 * into board.
 * Parameters: board - destination SIZE x SIZE grid, size - grid size
 * Returns: nothing
 */
void read_board(char board[][SIZE], int size) {
    char line[SIZE + 1];

    for (int r = 0; r < size; r++) {
        printf("Row %d: ", r + 1);
        scanf("%3s", line);
        for (int c = 0; c < size; c++) {
            board[r][c] = line[c];
        }
    }
}

/*
 * check_winner: checks every row, every column, and both diagonals for
 * three matching non-'.' characters in a row.
 * Parameters: board - SIZE x SIZE grid, size - grid size
 * Returns: the winning character ('X' or 'O'), or '.' if there is none
 */
char check_winner(const char board[][SIZE], int size) {
    for (int r = 0; r < size; r++) {
        int same = 1;
        for (int c = 1; c < size; c++) {
            if (board[r][c] != board[r][0]) {
                same = 0;
            }
        }
        if (same && board[r][0] != '.') {
            return board[r][0];
        }
    }

    for (int c = 0; c < size; c++) {
        int same = 1;
        for (int r = 1; r < size; r++) {
            if (board[r][c] != board[0][c]) {
                same = 0;
            }
        }
        if (same && board[0][c] != '.') {
            return board[0][c];
        }
    }

    int diag_same = 1;
    for (int i = 1; i < size; i++) {
        if (board[i][i] != board[0][0]) {
            diag_same = 0;
        }
    }
    if (diag_same && board[0][0] != '.') {
        return board[0][0];
    }

    int anti_diag_same = 1;
    for (int i = 1; i < size; i++) {
        if (board[i][size - 1 - i] != board[0][size - 1]) {
            anti_diag_same = 0;
        }
    }
    if (anti_diag_same && board[0][size - 1] != '.') {
        return board[0][size - 1];
    }

    return '.';
}
