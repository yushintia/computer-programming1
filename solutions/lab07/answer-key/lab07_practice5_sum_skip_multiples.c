/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice5_sum_skip_multiples.c
 * Description: Practice - reads n and k, then uses a for loop with
 *              continue to sum 1..n while skipping multiples of k.
 */
#include <stdio.h>

int main(void) {
    int n, k, i, sum;

    printf("Enter n: ");
    scanf("%d", &n);
    printf("Enter k (skip multiples of k): ");
    scanf("%d", &k);

    sum = 0;
    for (i = 1; i <= n; i++) {
        if (i % k == 0) {
            continue;
        }
        sum += i;
    }
    printf("Sum (excluding multiples of %d): %d\n", k, sum);

    return 0;
}
