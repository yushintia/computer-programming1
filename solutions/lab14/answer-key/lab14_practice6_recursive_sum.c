/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 14: Debugging, Analysis and Project Build
 * Filename : lab14_practice6_recursive_sum.c
 * Description: Corrected version of the buggy sum_down(n) recursion
 *              from Practice Problem 6. Sums the integers from n down
 *              to 0 and verifies predictions for n = 5, 10, and 0.
 *
 * Predictions (worked by hand before running):
 *   sum_down(5)  -> 5+4+3+2+1+0 = 15
 *   sum_down(10) -> 10+9+...+1+0 = 55
 *   sum_down(0)  -> base case hits immediately -> 0
 */

#include <stdio.h>

int sum_down(int n);

/*
 * main: runs sum_down on n = 5, 10, and 0 and prints each result so the
 * predictions above can be checked against actual output.
 * Parameters: none
 * Returns: 0 on success
 */
int main(void) {
    printf("sum_down(5)  = %d\n", sum_down(5));
    printf("sum_down(10) = %d\n", sum_down(10));
    printf("sum_down(0)  = %d\n", sum_down(0));
    return 0;
}

/*
 * sum_down: recursively sums the integers from n down to 0.
 * Parameters: n - starting value (n >= 0)
 * Returns: n + (n - 1) + ... + 1 + 0
 */
int sum_down(int n) {
    /* BUG FIX: the original had no base case, so sum_down kept calling
     * itself with a smaller n forever (n eventually goes negative and
     * never reaches a stopping point), crashing with a stack overflow.
     * Stopping at n <= 0 gives the recursion somewhere to return to. */
    if (n <= 0) {
        return 0;
    }
    return n + sum_down(n - 1);
}
