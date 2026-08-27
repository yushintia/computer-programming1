/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_transpose.c
 * Description: Challenge problem - transposes a square matrix in-place
 *              by swapping element [r][c] with element [c][r].
 */

#include <stdio.h>

#define N 4

void transpose(int m[][N], int n);
void print_matrix(const int m[][N], int n);

/*
 * main: builds a sample NxN matrix, prints it, transposes it in-place,
 * then prints the result so rows/columns swapping can be verified.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    int matrix[N][N] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    printf("Before transpose:\n");
    print_matrix(matrix, N);

    transpose(matrix, N);

    printf("\nAfter transpose:\n");
    print_matrix(matrix, N);

    return 0;
}

/*
 * transpose: transposes an n x n matrix in-place by swapping element
 * [r][c] with element [c][r] for every pair above the main diagonal.
 * Parameters: m - square matrix to transpose in place, n - dimension
 * Returns: nothing
 */
void transpose(int m[][N], int n) {
    for (int r = 0; r < n; r++) {
        for (int c = r + 1; c < n; c++) {
            int temp = m[r][c];
            m[r][c] = m[c][r];
            m[c][r] = temp;
        }
    }
}

/*
 * print_matrix: prints an n x n matrix with each value in a field of
 * width 5.
 * Parameters: m - matrix to print, n - dimension
 * Returns: nothing
 */
void print_matrix(const int m[][N], int n) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            printf("%5d", m[r][c]);
        }
        printf("\n");
    }
}
