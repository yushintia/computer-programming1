/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_practice1_multiples_of_seven.c
 * Description: Practice - uses a for loop to print all multiples of 7
 *              from 7 up to 70.
 */
#include <stdio.h>

#define STEP 7
#define LIMIT 70

int main(void) {
    int i;

    printf("Multiples of 7 up to %d:\n", LIMIT);
    for (i = STEP; i <= LIMIT; i += STEP) {
        printf("%d ", i);
    }
    printf("\n");

    return 0;
}
