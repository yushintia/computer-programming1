/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice7_digitproduct.c
 * Description: Practice problem - recursively multiplies the digits of a
 *              number, then repeatedly applies it in main to find the
 *              multiplicative persistence of 277 (steps to reach one digit).
 */
#include <stdio.h>

int digit_product(int n);

int main(void) {
    printf("digit_product(4) = %d\n", digit_product(4));
    printf("digit_product(39) = %d\n", digit_product(39));
    printf("digit_product(277) = %d\n", digit_product(277));

    int n = 277;
    int steps = 0;

    printf("Multiplicative persistence of 277:\n");
    while (n >= 10) {
        int next = digit_product(n);
        printf("  %d -> %d\n", n, next);
        n = next;
        steps++;
    }
    printf("Persistence steps: %d, final digit: %d\n", steps, n);

    return 0;
}

/*
 * digit_product: recursively multiplies together the decimal digits of a
 * non-negative integer.
 * Parameters: n - a non-negative integer
 * Returns: the product of the digits of n (n itself if n has one digit)
 */
int digit_product(int n) {
    if (n < 10) {
        return n;
    }
    return (n % 10) * digit_product(n / 10);
}
