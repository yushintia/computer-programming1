/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice1_donations.c
 * Description: Practice problem - recursively sums the first n days of
 *              donation totals (1 + 2 + ... + n).
 */
#include <stdio.h>

int sum_to_n(int n);

int main(void) {
    printf("sum_to_n(5) = %d\n", sum_to_n(5));
    printf("sum_to_n(10) = %d\n", sum_to_n(10));
    printf("sum_to_n(1) = %d\n", sum_to_n(1));

    return 0;
}

/*
 * sum_to_n: recursively sums the integers from 1 up to n.
 * Parameters: n - the upper bound (n >= 0)
 * Returns: the sum 1 + 2 + ... + n, or 0 if n <= 0
 */
int sum_to_n(int n) {
    if (n <= 0) {
        return 0;
    }
    return n + sum_to_n(n - 1);
}
