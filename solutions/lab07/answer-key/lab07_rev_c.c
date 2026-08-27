/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_rev_c.c
 * Description: Pre-midterm review C - reads a positive integer and
 *              prints its digits in reverse order.
 */
#include <stdio.h>

int main(void) {
    int num, digit;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    printf("Reversed: ");
    do {
        digit = num % 10;
        printf("%d", digit);
        num /= 10;
    } while (num > 0);
    printf("\n");

    return 0;
}
