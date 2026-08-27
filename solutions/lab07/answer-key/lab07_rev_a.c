/*
 * Course   : 400521-004 Computer Programming I
 * Instructor: Yushintia Pramitarini
 * Name     : [Instructor Reference Solution]
 * Student ID: N/A
 * Date     : 2026-08-28
 * Lab      : Lab 07: Loops II: for and Nested Loops
 * Filename : lab07_rev_a.c
 * Description: Pre-midterm review A - reads N integers and prints the
 *              largest and smallest of them.
 */
#include <stdio.h>

int main(void) {
    int count, i, value, largest, smallest;

    printf("How many integers? ");
    scanf("%d", &count);

    printf("Enter %d integers: ", count);
    scanf("%d", &value);
    largest = value;
    smallest = value;

    for (i = 2; i <= count; i++) {
        scanf("%d", &value);
        if (value > largest) {
            largest = value;
        }
        if (value < smallest) {
            smallest = value;
        }
    }

    printf("Largest = %d\n", largest);
    printf("Smallest = %d\n", smallest);

    return 0;
}
