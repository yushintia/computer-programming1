/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_triangle.c
 * Description: Refactors the Week 7 right-aligned triangle exercise into
 *              three cooperating functions: print_spaces, print_stars, and
 *              print_triangle.
 */
#include <stdio.h>

void print_spaces(int n);
void print_stars(int n);
void print_triangle(int rows);

int main(void) {
    int rows;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    print_triangle(rows);

    return 0;
}

/*
 * print_spaces: prints n space characters (no newline).
 * Parameters: n - number of spaces to print
 * Returns: nothing
 */
void print_spaces(int n) {
    for (int i = 0; i < n; i++) {
        printf(" ");
    }
}

/*
 * print_stars: prints n star characters separated by single spaces,
 * followed by a newline.
 * Parameters: n - number of stars to print
 * Returns: nothing
 */
void print_stars(int n) {
    for (int i = 0; i < n; i++) {
        printf("*");
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

/*
 * print_triangle: prints a right-aligned triangle of the given number of
 * rows using print_spaces and print_stars.
 * Parameters: rows - number of rows in the triangle
 * Returns: nothing
 */
void print_triangle(int rows) {
    for (int r = 1; r <= rows; r++) {
        print_spaces(2 * (rows - r));
        print_stars(r);
    }
}
