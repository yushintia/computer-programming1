/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice2_sum_evens.c
 * Description: Practice - reads N and uses a while loop to accumulate the
 *              sum of the even numbers from 1 to N.
 */
#include <stdio.h>

int main(void) {
    int n, i, sum;

    printf("Enter N: ");
    scanf("%d", &n);

    sum = 0;
    i = 2;
    while (i <= n) {
        sum += i;
        i += 2;
    }
    printf("Sum of even numbers from 1 to %d: %d\n", n, sum);

    return 0;
}
