/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 12: Arrays II (2-D Arrays & Strings)
 * Filename : lab12_practice7_magic_square.c
 * Description: Reads a 3x3 integer grid and reports whether every row
 *              sum, every column sum, and both diagonal sums are equal
 *              (a "magic square").
 */

#include <stdio.h>

#define SIZE 3

void read_grid(int grid[][SIZE], int size);
int is_magic_square(const int grid[][SIZE], int size);

/*
 * main: reads a SIZE x SIZE integer grid and reports whether it is a
 * magic square.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    int grid[SIZE][SIZE];

    printf("Enter %d integers for a %dx%d grid (row by row):\n",
           SIZE * SIZE, SIZE, SIZE);
    read_grid(grid, SIZE);

    if (is_magic_square(grid, SIZE)) {
        printf("This grid IS a magic square.\n");
    } else {
        printf("This grid is NOT a magic square.\n");
    }

    return 0;
}

/*
 * read_grid: reads size*size integers from stdin into grid, row by row.
 * Parameters: grid - destination grid, size - number of rows/columns
 * Returns: nothing
 */
void read_grid(int grid[][SIZE], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            scanf("%d", &grid[r][c]);
        }
    }
}

/*
 * is_magic_square: checks whether every row sum, every column sum, and
 * both diagonal sums of grid are all equal to each other.
 * Parameters: grid - square grid to check, size - number of rows/columns
 * Returns: 1 if grid is a magic square, 0 otherwise
 */
int is_magic_square(const int grid[][SIZE], int size) {
    int target = 0;
    for (int c = 0; c < size; c++) {
        target += grid[0][c];
    }

    for (int r = 0; r < size; r++) {
        int row_sum = 0;
        for (int c = 0; c < size; c++) {
            row_sum += grid[r][c];
        }
        if (row_sum != target) {
            return 0;
        }
    }

    for (int c = 0; c < size; c++) {
        int col_sum = 0;
        for (int r = 0; r < size; r++) {
            col_sum += grid[r][c];
        }
        if (col_sum != target) {
            return 0;
        }
    }

    int diag_sum = 0;
    int anti_diag_sum = 0;
    for (int i = 0; i < size; i++) {
        diag_sum += grid[i][i];
        anti_diag_sum += grid[i][size - 1 - i];
    }

    return diag_sum == target && anti_diag_sum == target;
}
