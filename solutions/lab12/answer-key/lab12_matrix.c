/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_matrix.c
 * Description: Reads a 3x4 integer matrix, prints it formatted, then
 *              prints each row sum, each column sum, and the grand total.
 */

#include <stdio.h>

#define ROWS 3
#define COLS 4
#define FIELD_WIDTH 5

void read_matrix(int m[][COLS], int rows, int cols);
void print_matrix(const int m[][COLS], int rows, int cols);
void print_row_sums(const int m[][COLS], int rows, int cols);
void print_col_sums(const int m[][COLS], int rows, int cols);
int matrix_total(const int m[][COLS], int rows, int cols);

/*
 * main: reads a ROWS x COLS matrix, prints it, then prints row sums,
 * column sums, and the grand total.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    int matrix[ROWS][COLS];

    printf("Enter %d integers for a %dx%d matrix (row by row):\n",
           ROWS * COLS, ROWS, COLS);
    read_matrix(matrix, ROWS, COLS);

    printf("\nMatrix:\n");
    print_matrix(matrix, ROWS, COLS);

    printf("\nRow sums:\n");
    print_row_sums(matrix, ROWS, COLS);

    printf("\nColumn sums:\n");
    print_col_sums(matrix, ROWS, COLS);

    printf("\nGrand total: %d\n", matrix_total(matrix, ROWS, COLS));

    return 0;
}

/*
 * read_matrix: reads rows*cols integers from stdin into m.
 * Parameters: m - destination matrix, rows/cols - dimensions
 * Returns: nothing
 */
void read_matrix(int m[][COLS], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            scanf("%d", &m[r][c]);
        }
    }
}

/*
 * print_matrix: prints m with each value in a field of FIELD_WIDTH.
 * Parameters: m - matrix to print, rows/cols - dimensions
 * Returns: nothing
 */
void print_matrix(const int m[][COLS], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            printf("%*d", FIELD_WIDTH, m[r][c]);
        }
        printf("\n");
    }
}

/*
 * print_row_sums: prints the sum of each row of m, one per line.
 * Parameters: m - matrix, rows/cols - dimensions
 * Returns: nothing
 */
void print_row_sums(const int m[][COLS], int rows, int cols) {
    for (int r = 0; r < rows; r++) {
        int row_sum = 0;
        for (int c = 0; c < cols; c++) {
            row_sum += m[r][c];
        }
        printf("Row %d sum: %d\n", r, row_sum);
    }
}

/*
 * print_col_sums: prints the sum of each column of m, one per line.
 * Parameters: m - matrix, rows/cols - dimensions
 * Returns: nothing
 */
void print_col_sums(const int m[][COLS], int rows, int cols) {
    for (int c = 0; c < cols; c++) {
        int col_sum = 0;
        for (int r = 0; r < rows; r++) {
            col_sum += m[r][c];
        }
        printf("Col %d sum: %d\n", c, col_sum);
    }
}

/*
 * matrix_total: returns the sum of every element in m.
 * Parameters: m - matrix, rows/cols - dimensions
 * Returns: the grand total as an int
 */
int matrix_total(const int m[][COLS], int rows, int cols) {
    int total = 0;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            total += m[r][c];
        }
    }
    return total;
}
