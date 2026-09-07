/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice4_prime_check.c
 * Description: Practice - reads a positive integer and uses a for loop
 *              with break to test whether it is prime.
 */
#include <stdio.h>

int main(void) {
    int n, i, is_prime;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    is_prime = 1;
    if (n < 2) {
        is_prime = 0;
    } else {
        for (i = 2; i < n; i++) {
            if (n % i == 0) {
                is_prime = 0;
                break;
            }
        }
    }

    if (is_prime == 1) {
        printf("%d is Prime\n", n);
    } else {
        printf("%d is Not prime\n", n);
    }

    return 0;
}
