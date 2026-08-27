/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 08: Midterm Sample Practice
 * Filename : lab08_practice1_sum_odds.c
 * Description: Practice 1 - reads N and prints the sum of odd numbers
 *              from 1 to N.
 */
#include <stdio.h>

int main(void) {
    int n, i, sum;

    printf("Enter N: ");
    scanf("%d", &n);

    sum = 0;
    for (i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            sum += i;
        }
    }

    printf("Sum of odd numbers from 1 to %d = %d\n", n, sum);

    return 0;
}
