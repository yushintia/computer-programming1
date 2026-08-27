/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_sum.c
 * Description: Reads N and computes the sum 1..N using a while loop,
 *              then verifies it against the closed-form formula N*(N+1)/2.
 */
#include <stdio.h>

int main(void) {
    int n, i, sum, formula_sum;

    printf("Enter N: ");
    scanf("%d", &n);

    sum = 0;
    i = 1;
    while (i <= n) {
        sum += i;
        i++;
    }

    formula_sum = n * (n + 1) / 2;

    printf("Sum (loop)    = %d\n", sum);
    printf("Sum (formula) = %d\n", formula_sum);

    return 0;
}
