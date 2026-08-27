/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_diamond.c
 * Description: Challenge - prints a diamond pattern of stars; the number
 *              of rows in the top half is read from the user.
 */
#include <stdio.h>

/*
 * print_diamond_row: prints one row of the diamond with the given
 * number of leading spaces followed by the given number of stars.
 * Parameters: spaces - number of leading blank characters
 *             stars  - number of '*' characters to print
 * Returns: nothing
 */
void print_diamond_row(int spaces, int stars) {
    int i;

    for (i = 1; i <= spaces; i++) {
        printf(" ");
    }
    for (i = 1; i <= stars; i++) {
        printf("*");
    }
    printf("\n");
}

int main(void) {
    int n, i;

    printf("Enter top-half rows: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        print_diamond_row(n - i + 1, 2 * i - 1);
    }
    for (i = n - 1; i >= 1; i--) {
        print_diamond_row(n - i + 1, 2 * i - 1);
    }

    return 0;
}
