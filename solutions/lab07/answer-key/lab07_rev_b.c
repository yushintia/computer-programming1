/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_rev_b.c
 * Description: Pre-midterm review B - prints integers 1 to 100 that are
 *              divisible by 3 or 5, but not both.
 */
#include <stdio.h>

#define RANGE_MAX 100
#define DIVISOR_A 3
#define DIVISOR_B 5

int main(void) {
    int i, div_a, div_b;

    for (i = 1; i <= RANGE_MAX; i++) {
        div_a = (i % DIVISOR_A == 0);
        div_b = (i % DIVISOR_B == 0);
        if ((div_a || div_b) && !(div_a && div_b)) {
            printf("%d\n", i);
        }
    }

    return 0;
}
