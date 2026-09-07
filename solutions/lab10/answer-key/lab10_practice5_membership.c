/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 10: Functions II: Scope & Recursion
 * Filename : lab10_practice5_membership.c
 * Description: Practice problem - recursively computes the nth term of an
 *              arithmetic sequence, modeling a gym membership fee that
 *              increases by a fixed amount each year.
 */
#include <stdio.h>

int nth_term(int first_term, int common_diff, int n);

int main(void) {
    printf("nth_term(50, 10, 4) = %d\n", nth_term(50, 10, 4));
    printf("nth_term(50, 10, 1) = %d\n", nth_term(50, 10, 1));
    printf("nth_term(100, 25, 5) = %d\n", nth_term(100, 25, 5));

    return 0;
}

/*
 * nth_term: recursively computes the nth term of an arithmetic sequence.
 * Parameters: first_term - the value of term 1, common_diff - the fixed
 * amount added each term, n - which term to compute (n >= 1)
 * Returns: first_term + common_diff * (n - 1)
 */
int nth_term(int first_term, int common_diff, int n) {
    if (n == 1) {
        return first_term;
    }
    return common_diff + nth_term(first_term, common_diff, n - 1);
}
