/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_fib.c
 * Description: Naive recursive Fibonacci function; prints fib(0) through
 *              fib(10) and notes the exponential growth of this approach.
 */
#include <stdio.h>

#define FIB_LIMIT 10

int fib(int n);

int main(void) {
    for (int i = 0; i <= FIB_LIMIT; i++) {
        printf("fib(%d) = %d\n", i, fib(i));
    }

    return 0;
}

/*
 * fib: returns the nth Fibonacci number using naive recursion.
 * Parameters: n - index into the Fibonacci sequence (n >= 0)
 * Returns: the nth Fibonacci number
 *
 * Note: this is the naive exponential-time version. Each call (for n > 1)
 * spawns two more recursive calls, so the number of calls roughly doubles
 * with each increase in n. It is intentionally left unoptimized (no
 * memoization) to illustrate why this approach becomes slow for larger n.
 */
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}
