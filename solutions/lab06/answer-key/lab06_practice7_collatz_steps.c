/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 06: Loops I: while and do-while
 * Filename : lab06_practice7_collatz_steps.c
 * Description: Practice - reads a positive integer and counts how many
 *              Collatz-sequence steps it takes to reach 1.
 */
#include <stdio.h>

int main(void) {
    int n, steps;

    printf("Enter a positive integer: ");
    scanf("%d", &n);

    steps = 0;
    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }
        steps++;
    }
    printf("Steps to reach 1: %d\n", steps);

    return 0;
}
