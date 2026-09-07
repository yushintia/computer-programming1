/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice2_sum_of_squares.c
 * Description: Practice - reads n and uses a for loop to compute the sum
 *              of the squares of 1 through n.
 */
#include <stdio.h>

int main(void) {
    int n, i, sum;

    printf("Enter n: ");
    scanf("%d", &n);

    sum = 0;
    for (i = 1; i <= n; i++) {
        sum += i * i;
    }
    printf("Sum of squares: %d\n", sum);

    return 0;
}
