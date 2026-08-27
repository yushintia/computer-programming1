/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_trace.c
 * Description: Traces the mystery(n) function from the lab's worked
 *              example (sums the odd integers from 1 to n) and verifies
 *              predictions for n = 5, 10, and 0.
 *
 * Predictions (worked by hand before running):
 *   mystery(5)  -> odd numbers 1..5 are 1, 3, 5 -> 1+3+5 = 9
 *   mystery(10) -> odd numbers 1..10 are 1,3,5,7,9 -> 1+3+5+7+9 = 25
 *   mystery(0)  -> loop from i=1 to i<=0 never runs -> result stays 0
 */

#include <stdio.h>

int mystery(int n);

/*
 * main: runs mystery on n = 5, 10, and 0 and prints each result so the
 * predictions above can be checked against actual output.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    printf("mystery(5)  = %d\n", mystery(5));
    printf("mystery(10) = %d\n", mystery(10));
    printf("mystery(0)  = %d\n", mystery(0));
    return 0;
}

/*
 * mystery: sums the odd integers from 1 to n, inclusive.
 * Parameters: n - upper bound of the range (may be 0 or negative)
 * Returns: the sum of all odd integers in [1, n]
 */
int mystery(int n) {
    int result = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) {
            result += i;
        }
    }
    return result;
}
