/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_gcd.c
 * Description: Challenge problem - compares a recursive Euclidean gcd with
 *              an iterative gcd on several test pairs.
 */
#include <stdio.h>

int gcd_recursive(int a, int b);
int gcd_iterative(int a, int b);

int main(void) {
    int pairs[][2] = {{48, 18}, {20, 8}, {17, 5}, {7, 0}, {100, 75}};
    int num_pairs = 5;

    for (int i = 0; i < num_pairs; i++) {
        int a = pairs[i][0];
        int b = pairs[i][1];
        int recursive_result = gcd_recursive(a, b);
        int iterative_result = gcd_iterative(a, b);

        printf("gcd(%d,%d): recursive = %d, iterative = %d, match = %s\n",
               a, b, recursive_result, iterative_result,
               (recursive_result == iterative_result) ? "yes" : "no");
    }

    return 0;
}

/*
 * gcd_recursive: computes the greatest common divisor of a and b using the
 * recursive Euclidean algorithm.
 * Parameters: a, b - non-negative integers
 * Returns: the greatest common divisor of a and b
 */
int gcd_recursive(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd_recursive(b, a % b);
}

/*
 * gcd_iterative: computes the greatest common divisor of a and b using an
 * iterative loop version of the Euclidean algorithm.
 * Parameters: a, b - non-negative integers
 * Returns: the greatest common divisor of a and b
 */
int gcd_iterative(int a, int b) {
    while (b != 0) {
        int remainder = a % b;
        a = b;
        b = remainder;
    }
    return a;
}
