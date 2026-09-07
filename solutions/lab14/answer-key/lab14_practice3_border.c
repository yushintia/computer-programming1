/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice3_border.c
 * Description: Corrected version of the buggy grid border painter from
 *              Practice Problem 3. Fills a square grid with '*' along
 *              the border and '.' everywhere inside, then prints it.
 */

#include <stdio.h>

#define SIZE 4

void paint_border(char grid[][SIZE], int size);
void print_grid(const char grid[][SIZE], int size);

/*
 * main: paints the border of a SIZE x SIZE grid and prints it.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    char grid[SIZE][SIZE];

    paint_border(grid, SIZE);
    print_grid(grid, SIZE);

    return 0;
}

/*
 * paint_border: sets every border cell of grid to '*' and every
 * interior cell to '.'.
 * Parameters: grid - destination size x size grid, size - grid size
 * Returns: nothing
 */
void paint_border(char grid[][SIZE], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            /* BUG FIX: the original compared r and c to size, but valid
             * indices only go up to size - 1, so r == size and
             * c == size were always false and the bottom row and right
             * column never got painted. Comparing to size - 1 fixes it. */
            if (r == 0 || r == size - 1 || c == 0 || c == size - 1) {
                grid[r][c] = '*';
            } else {
                grid[r][c] = '.';
            }
        }
    }
}

/*
 * print_grid: prints each row of grid as a line of characters.
 * Parameters: grid - size x size grid, size - grid size
 * Returns: nothing
 */
void print_grid(const char grid[][SIZE], int size) {
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            printf("%c", grid[r][c]);
        }
        printf("\n");
    }
}
